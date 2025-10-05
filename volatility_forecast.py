# volatility_forecast.py

import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import streamlit as st
from arch import arch_model

# -------------------------
# CONFIGURATION
# -------------------------
TICKER = "AAPL"
PERIOD = "2y"

# -------------------------
# FETCH DATA
# -------------------------
def fetch_data(ticker, period="2y"):
    data = yf.download(ticker, period=period, interval="1d")
    data["Returns"] = data["Close"].pct_change().dropna()
    return data

# -------------------------
# GARCH VOLATILITY MODEL
# -------------------------
def forecast_volatility(returns, horizon=5):
    model = arch_model(returns.dropna()*100, vol="GARCH", p=1, q=1)
    res = model.fit(disp="off")
    forecast = res.forecast(horizon=horizon)
    return forecast.variance.iloc[-1]**0.5

# -------------------------
# VALUE AT RISK (VaR)
# -------------------------
def calculate_var(returns, confidence=0.95):
    mean = returns.mean()
    std = returns.std()
    var = np.percentile(returns, (1-confidence)*100)
    return var

# -------------------------
# STREAMLIT DASHBOARD
# -------------------------
st.title("📡 Volatility & Risk Management")
st.write(f"Risk analysis for {TICKER}")

# Fetch Data
data = fetch_data(TICKER)
st.line_chart(data["Close"], height=300)

# Forecast Volatility
vol_forecast = forecast_volatility(data["Returns"])
st.metric(label="📉 Forecasted Volatility (Next 5 Days)", value=f"{vol_forecast.mean():.2f}%")

# Value at Risk
var_95 = calculate_var(data["Returns"], 0.95)
var_99 = calculate_var(data["Returns"], 0.99)

st.metric(label="⚠️ Value at Risk (95%)", value=f"{var_95:.2%}")
st.metric(label="⚠️ Value at Risk (99%)", value=f"{var_99:.2%}")

# Visualization
st.subheader("Return Distribution")
fig, ax = plt.subplots()
data["Returns"].hist(bins=50, ax=ax)
ax.set_title("Return Distribution")
st.pyplot(fig)
