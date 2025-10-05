# options_pricing.py

import numpy as np
import yfinance as yf
import streamlit as st
from scipy.stats import norm
import datetime

# -------------------------
# CONFIGURATION
# -------------------------
TICKER = "AAPL"
RISK_FREE_RATE = 0.05  # 5% annual risk-free rate

# -------------------------
# BLACK-SCHOLES FUNCTIONS
# -------------------------
def black_scholes(S, K, T, r, sigma, option_type="call"):
    """ Black-Scholes formula for European options """
    d1 = (np.log(S/K) + (r + 0.5*sigma**2)*T) / (sigma*np.sqrt(T))
    d2 = d1 - sigma*np.sqrt(T)
    
    if option_type == "call":
        price = S*norm.cdf(d1) - K*np.exp(-r*T)*norm.cdf(d2)
    else:
        price = K*np.exp(-r*T)*norm.cdf(-d2) - S*norm.cdf(-d1)
    return price

def option_greeks(S, K, T, r, sigma, option_type="call"):
    d1 = (np.log(S/K) + (r + 0.5*sigma**2)*T) / (sigma*np.sqrt(T))
    d2 = d1 - sigma*np.sqrt(T)

    delta = norm.cdf(d1) if option_type == "call" else -norm.cdf(-d1)
    gamma = norm.pdf(d1) / (S*sigma*np.sqrt(T))
    theta = -(S*norm.pdf(d1)*sigma) / (2*np.sqrt(T)) - r*K*np.exp(-r*T)*(norm.cdf(d2) if option_type=="call" else norm.cdf(-d2))
    vega = S*norm.pdf(d1)*np.sqrt(T)
    rho = K*T*np.exp(-r*T)*(norm.cdf(d2) if option_type=="call" else -norm.cdf(-d2))

    return {
        "Delta": delta,
        "Gamma": gamma,
        "Theta": theta/365,  # per day
        "Vega": vega/100,    # per 1% change in volatility
        "Rho": rho/100       # per 1% change in rates
    }

# -------------------------
# FETCH LIVE DATA
# -------------------------
data = yf.download(TICKER, period="1d", interval="1d")
S = data["Close"].iloc[-1]  # Current stock price

# -------------------------
# STREAMLIT DASHBOARD
# -------------------------
st.title("💹 Options Pricing & Greeks")
st.write(f"Stock: {TICKER} | Current Price: ${S:.2f}")

# User Inputs
K = st.number_input("Strike Price", value=float(S), step=5.0)
days = st.slider("Days to Expiry", 1, 365, 30)
sigma = st.slider("Volatility (σ)", 10, 80, 25) / 100
T = days / 365

option_type = st.selectbox("Option Type", ["call", "put"])

# Pricing
price = black_scholes(S, K, T, RISK_FREE_RATE, sigma, option_type)
greeks = option_greeks(S, K, T, RISK_FREE_RATE, sigma, option_type)

# Display
st.metric(label=f"📈 {option_type.upper()} Option Price", value=f"${price:.2f}")

st.subheader("Option Greeks")
for g, v in greeks.items():
    st.write(f"**{g}**: {v:.4f}")
