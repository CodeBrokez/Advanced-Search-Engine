# Advanced-Search-Engine

An intelligent search engine built using web scraping and Natural Language Processing (NLP) to rank web pages based on semantic relevance to a given search query. This project combines several advanced technologies to provide accurate and meaningful search results from the web.

## Features

- **Web Scraping**: Extracts links from web pages using the `BeautifulSoup` library.
- **Semantic Search**: Ranks web pages based on semantic relevance to a user-provided query using machine learning models.
- **NLP Integration**: Leverages `spaCy` for text processing and HuggingFace's `transformers` library for text classification.
- **Multi-Language Support**: Works with content in multiple languages, provided the appropriate model is used.

## Technologies Used

- **Python**: The core language used for the project.
- **BeautifulSoup**: For scraping and parsing HTML content from web pages.
- **spaCy**: For Natural Language Processing tasks such as tokenization, named entity recognition (NER), and part-of-speech tagging.
- **HuggingFace Transformers**: For semantic text classification using pre-trained transformer models.
- **Requests**: For handling HTTP requests to fetch content from URLs.
- **Machine Learning**: The project uses semantic similarity models for ranking the relevance of the web pages.
