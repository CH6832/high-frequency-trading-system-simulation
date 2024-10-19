import json

class Config:
    @staticmethod
    def load_config(filename):
        """
        Load configuration from a JSON file.
        
        :param filename: Path to the JSON config file.
        :return: Parsed JSON data.
        """
        with open(filename, 'r') as file:
            return json.load(file)
