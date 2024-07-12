import random
import subprocess

def _generate_set(size, start, end) -> list:
    if size < 0:
        return []
    
    if start > end:
        return []
    
    return random.sample(range(start, end + 1), size)

def test_sort():
    subprocess.run(['make', 're'])
    for i in range(0, 100):
        size = random.randint(10, 100)
        start = random.randint(1, 1001)
        end = random.randint(1001, 10011)
        set = _generate_set(size, start, end)
        sorted_set = sorted(set)
        process = subprocess.run(['./PmergeMe', f"{','.join(map(str, set))}"], capture_output=True)
        # assert process.returncode == 0
        print(f"Retirn code: {process.returncode}")
        # print(' '.join(map(str, sorted_set)))
        assert process.stdout.decode().strip() == ' '.join(map(str, sorted_set))

test_sort()