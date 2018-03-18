
from random import randint

def get_new_distribution():
    """ Returns an array with 1 for the winning position """
    dist = [0,0,0]
    dist[randint(0,2)] = 1
    return dist

def get_hint(dist, choice):
    """ Simulate hint from the host for choice.
    Indicates a not winning position. """
    for i in range(len(dist)):
        if not dist[i] and i != choice:
            return i
    raise Exception("Broken implementation")

def change_choice(choice, hint):
    """ Get the third option """
    return 3 - choice - hint

def run_one_similuation(change_strategy):
    """ Run one simulation for a given strategy.
    Returns 1 if strategy won, 0 otherwise. """
    
    dist = get_new_distribution()
    choice = randint(0,2)
    hint = get_hint(dist, choice)

    if change_strategy:
        choice = change_choice(choice, hint)

    return dist[choice]

def run_simulation(sample):
    successes_change = 0
    successes_not_change = 0
    for i in range(sample):
        successes_change += run_one_similuation(True)
        successes_not_change += run_one_similuation(False)

    print float(successes_change) / sample
    print float(successes_not_change) / sample

run_simulation(1000000)
