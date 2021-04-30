import sys
from threading import Lock
import json

class Stats:

    def __init__(self):
        self.lock = Lock()
        self.stats = {}

    def save_json(self, filepath):
        with open(filepath, "w") as fo:
            json.dump(self.stats, fo, indent=4, sort_keys=True)

    def print_stats(self):
        # emit start/end time
        # emit %success
        self.print_json()

    def print_json(self):
        self.save_json("/dev/stdout")

    def add_stat(self, key, value):
        with self.lock:
            self.stats.setdefault(key, []).append(value)

    def inc_stat(self, key):
        # probably needs a lock but #YOLO
        item = self.stats.get(key, 0)
        self.stats[key] = item + 1

    def set_stat(self, key, value):
        # probably needs a lock but #YOLO
        self.stats[key] = value
