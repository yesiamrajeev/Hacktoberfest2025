# live_stock_dashboard.py

import numpy as np
import pandas as pd
import yfinance as yf
import streamlit as st
from sklearn.preprocessing import MinMaxScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense, Dropout
import matplotlib.pyplot as plt
import datetime

# -------------------------
# CONFIGURATION
# -------------------------
TICKER = "AAPL"
LOOKBACK = 60
REFRESH_MINUTES = 5

# -------------------------
# FETCH LIVE DATA
# -------------------------
def fetch_live_data(ticker, period="6mo", interval="15m"):
    data = yf.download(ticker, period=period, interval=interval)
    return data

# -------------------------
# PREPROCESS
# -------------------------
def preprocess_data(data, lookback=60):
    scaler = MinMaxScaler()
    scaled = scaler.fit_transform(data["Close"].values.reshape(-1, 1))

    X, y = [], []
    for i in range(lookback, len(scaled)):
        X.append(scaled[i-lookback:i, 0])
        y.append(scaled[i, 0])
    return np.array(X).reshape(-1, lookback, 1), np.array(y), scaler

# -------------------------
# MODEL
# -------------------------
def build_model(input_shape):
    model = Sequential()
    model.add(LSTM(50, return_sequences=True, input_shape=input_shape))
    model.add(Dropout(0.2))
    model.add(LSTM(50))
    model.add(Dropout(0.2))
    model.add(Dense(1))
    model.compile(optimizer="adam", loss="mean_squared_error")
    return model

# -------------------------
# STREAMLIT DASHBOARD
# -------------------------
st.title("📈 Real-Time Stock Prediction Dashboard")
st.write(f"Live predictions for {TICKER}")

data = fetch_live_data(TICKER)
st.line_chart(data["Close"], height=300)

X, y, scaler = preprocess_data(data, LOOKBACK)
split = int(len(X) * 0.8)
X_train, X_test = X[:split], X[split:]
y_train, y_test = y[:split], y[split:]

model = build_model((X_train.shape[1], 1))
model.fit(X_train, y_train, epochs=10, batch_size=32, verbose=0)

# Prediction
last_data = data["Close"].values[-LOOKBACK:]
scaled_last = scaler.transform(last_data.reshape(-1, 1))
X_input = scaled_last.reshape(1, LOOKBACK, 1)
next_pred = model.predict(X_input)[0][0]
next_price = scaler.inverse_transform([[next_pred]])[0][0]

st.metric(label="Latest Price", value=f"${data['Close'].iloc[-1]:.2f}")
st.metric(label="Predicted Next Price", value=f"${next_price:.2f}")

if next_price > data["Close"].iloc[-1]:
    st.success("✅ Signal: BUY (Uptrend expected)")
else:
    st.error("⚠️ Signal: SELL (Downtrend expected)")

st.caption(f"Last updated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')} | Refresh every {REFRESH_MINUTES} mins")
