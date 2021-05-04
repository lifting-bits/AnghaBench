from re import I
import sys
from threading import Lock
import json
from datetime import datetime


class Stats:
    def __init__(self):
        self.lock = Lock()
        self.stats = {}

    def save_json(self, filepath):
        with open(filepath, "w") as fo:
            json.dump(self.stats, fo, indent=4, sort_keys=True)

    def print_fails(self, fail_count=5, output=None):
        if output is None:
            output = sys.stderr

        # Do a dictionary comprehension to filter for keys that
        # start with "output.", but ignore the success case, since
        # we only want the failures here
        out_stats = {
            k: v
            for k, v in self.stats.items()
            if k.startswith("output.") and k != "output.success"
        }

        # Sort dictionary by length of key
        top_items = sorted(out_stats.items(), reverse=True, key=lambda x: len(x[1]))

        # Output the top fail_count items
        for k, v in top_items[:fail_count]:
            k = k.replace("output.", "")
            output.write(f"`{k}`: `{len(v)}` failures\n")

    def print_stats(self, output=None):
        # emit start/end time
        # emit %success

        if output is None:
            output = sys.stderr

        if "start_time" in self.stats and "end_time" in self.stats:
            start_time = datetime.fromisoformat(self.stats["start_time"])
            end_time = datetime.fromisoformat(self.stats["end_time"])

            time_diff = end_time - start_time
            secs = time_diff.total_seconds()

            output.write(f"Run took {time_diff}\n")

            if "program_runs" in self.stats:
                runs = self.stats["program_runs"]
                runs_per_sec = runs / secs
                output.write(f"Speed of {runs_per_sec:.2f} runs/sec\n")

        success_runs = self.stats.get("output.success", [])
        program_runs = self.stats.get("program_runs", 0)

        success_items = len(success_runs)
        success_percent = 100.0 * success_items / program_runs

        if program_runs != 0:
            output.write(f"Success Metrics: [{success_items}/{program_runs}]\n")
            output.write(f"Success Percentage: [{success_percent:.2f}%]\n")

        if output is not None:
            output.flush()

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
