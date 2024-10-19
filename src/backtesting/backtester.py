import cProfile
import pstats

class Backtester:
    def __init__(self, strategy):
        self.strategy = strategy

    def run(self, price_data):
        """
        Run backtesting on the given price data using the strategy.
        """
        signals = []
        with cProfile.Profile() as pr:
            for i in range(len(price_data)):
                current_history = price_data[max(0, i - self.strategy.lookback_period):i + 1]
                signal = self.strategy.generate_signal(current_history)
                signals.append(signal)
        pr.dump_stats("backtester_profile.prof")
        return signals
