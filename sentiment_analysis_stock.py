# sentiment_analysis_stock.py

import yfinance as yf
import pandas as pd
import requests
from textblob import TextBlob
import streamlit as st
import datetime

# -------------------------
# CONFIGURATION
# -------------------------
TICKER = "AAPL"
NEWS_API_KEY = "your_news_api_key"  # Get from https://newsapi.org

# -------------------------
# FETCH STOCK DATA
# -------------------------
def fetch_stock_data(ticker, period="1mo", interval="1d"):
    return yf.download(ticker, period=period, interval=interval)

# -------------------------
# FETCH NEWS HEADLINES
# -------------------------
def fetch_news(query, api_key, page_size=10):
    url = (f"https://newsapi.org/v2/everything?"
           f"q={query}&sortBy=publishedAt&language=en&pageSize={page_size}&apiKey={api_key}")
    response = requests.get(url).json()
    if response["status"] == "ok":
        return [(a["title"], a["publishedAt"]) for a in response["articles"]]
    return []

# -------------------------
# SENTIMENT ANALYSIS
# -------------------------
def analyze_sentiment(text):
    polarity = TextBlob(text).sentiment.polarity
    if polarity > 0:
        return "Positive"
    elif polarity < 0:
        return "Negative"
    else:
        return "Neutral"

# -------------------------
# STREAMLIT DASHBOARD
# -------------------------
st.title("📈 Stock Sentiment Dashboard")
st.write(f"Analyzing sentiment for **{TICKER}**")

# Stock Chart
data = fetch_stock_data(TICKER)
st.line_chart(data["Close"], height=300)

# Fetch News
st.subheader("📰 Latest News Sentiment")
news = fetch_news(TICKER, NEWS_API_KEY)

if news:
    sentiments = []
    for title, published in news:
        sentiment = analyze_sentiment(title)
        sentiments.append(sentiment)
        st.write(f"**{title}** ({published[:10]}) → {sentiment}")

    # Summary
    sentiment_counts = pd.Series(sentiments).value_counts()
    st.bar_chart(sentiment_counts)
else:
    st.warning("No news articles found. Check API key or query.")

# Decision
if news:
    positive_ratio = sentiments.count("Positive") / len(sentiments)
    if positive_ratio > 0.6:
        st.success("✅ Overall Sentiment: BUY (Positive Market Mood)")
    elif sentiments.count("Negative") > sentiments.count("Positive"):
        st.error("⚠️ Overall Sentiment: SELL (Negative Market Mood)")
    else:
        st.info("🔄 Overall Sentiment: HOLD (Mixed Market Mood)")

st.caption(f"Last updated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
