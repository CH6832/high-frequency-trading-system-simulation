import requests
import logging

class DataFetcher:
    def __init__(self):
        self.logger = logging.getLogger(__name__)

    def fetch_data(self, url):
        """
        Fetch data from the specified URL.

        :param url: URL to fetch data from.
        :return: Parsed JSON response.
        :raises Exception: If fetching data fails.
        """
        try:
            response = requests.get(url)
            response.raise_for_status()  # Raises an error for bad responses
            self.logger.info(f"Data fetched successfully from {url}")
            return response.json()
        except requests.exceptions.RequestException as e:
            self.logger.error(f"Error fetching data from {url}: {e}")
            raise
