import random
import subprocess


class Analyzer:
    def __init__(self):
        self._errors = 0
        self._success = 0
        self.error_list = []
        self.table = {}

    def add_error(self, error: str = None):
        self._errors += 1
        if error:
            self.error_list.append(error)

    def add_success(self):
        self._success += 1

    def extract_data(self, stdout: str, sample_size: int):
        lines = stdout.split('\n')[-5:]
        deque_duration = 0
        vector_duration = 0
        for line in lines:
            if 'Deque' in line:
                deque_duration = int(line.split(' ')[-2])
            elif 'Vector' in line:
                vector_duration = int(line.split(' ')[-2])
        if deque_duration > 0 and vector_duration > 0:
            self._add_to_table(sample_size, deque_duration, vector_duration)

    def _add_to_table(self, sample_size: int, deque_duration: int, vector_duration: int):
        node = self.table.get(sample_size)
        if (node):
            node['deque'].append(deque_duration)
            node['vector'].append(vector_duration)
        else:
            self.table[sample_size] = {
                'deque': [deque_duration],
                'vector': [vector_duration]
            }

    def write_map_to_csv(self):
        with open('report.csv', 'w') as file:
            file.write('size,deque,vector\n')
            for key, value in self.table.items():
                deque_avg = sum(value['deque']) / len(value['deque'])
                vector_avg = sum(value['vector']) / len(value['vector'])
                file.write(f"{key},{deque_avg},{vector_avg}\n")

    def write_all_to_csv(self):
        with open('dataset.csv', 'w') as file:
            file.write('size,deque,vector\n')
            for key, value in self.table.items():
                for i in range(0, len(value['deque'])):
                    file.write(f"{key},{value['deque'][i]},{value['vector'][i]}\n")

    def report(self):
        self.table = {k: v for k, v in sorted(self.table.items(), key=lambda item: item[0])}
        average_percentage = []
        for key, value in self.table.items():
            deque_avg = sum(value['deque']) / len(value['deque'])
            vector_avg = sum(value['vector']) / len(value['vector'])
            print(f"Input Size: {key} | Sample Size: {len(value['deque'])} | Vector: {vector_avg} | Deque: {deque_avg}")
            print(f"Diff: {deque_avg - vector_avg}")
            avg_per = (deque_avg - vector_avg) / vector_avg * 100
            print(f"Percentage: {avg_per}")
            average_percentage.append(avg_per)
            print("------------")
        print(f"Average Percentage: {sum(average_percentage) / len(average_percentage)}")
        print(f"Success: {self._success}")
        print(f"Errors: {self._errors}")
        if self._errors > 0:
            print("Errors:")
            for error in self.error_list:
                print(error)
        self.write_map_to_csv()
        self.write_all_to_csv()


def _generate_set(size, start, end) -> list:
    if size < 0:
        return []
    if start > end:
        return []
    return random.sample(range(start, end + 1), size)


def test_sort():
    subprocess.run(['make', 're'])
    lyz = Analyzer()
    for i in range(0, 50):
        size = random.randint(10, 5000)
        start = random.randint(0, 200)
        end = random.randint(6000, 100000)
        for i in range(0, 10):
            set = _generate_set(size, start, end)
            sorted_set = sorted(set)
            stringified_set = ' '.join(map(str, set))
            process = subprocess.run(
                ['./PmergeMe', stringified_set],
                capture_output=True, text=True
            )
            if (process.returncode != 0):
                lyz.add_error(process.stderr.strip())
            print(process.stdout.strip())
            print(f"Sample Size: {size}")
            if ' '.join(map(str, sorted_set)) in process.stdout.strip():
                lyz.add_success()
                lyz.extract_data(process.stdout.strip(), size)
            else:
                lyz.add_error(f"Error in test {i}, output does not match, input: {stringified_set}")
    print("Done. Reporting...")
    lyz.report()


test_sort()
