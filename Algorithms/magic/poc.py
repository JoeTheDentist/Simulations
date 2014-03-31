
from math import factorial
import sys

def set_magic_number(cards, magic_number, start = 0):
    """
    Permute according to the magic number.
    O(n^2) recursive + pop
    """
    if start + 1 == len(cards):
        return
    step = len(cards) - start
    div = factorial(step - 1)
    index = (magic_number - 1) / div + start
    card = cards.pop(index)
    cards.insert(start, card)
    set_magic_number(cards, magic_number - index * div, start + 1)

def get_magic_number(cards):
    """
    Get the number from the permutation.
    O(n^2)
    """
    size = len(cards)
    magic_number = 0
    for i in range(size-1):
        # Get position
        position = 0
        for j in range(i+1, size):
            if cards[j] < cards[i]:
                position += 1
        magic_number += position * (size - 1 - i)
    return magic_number + 1

def compute_combination(cards):
    """
    Compute the combination, removing a card and sort the remaining cards.
    O(n^2)
    """
    sorted_cards = sorted(cards)
    index_to_remove = 0
    step = len(cards)
    fact = factorial(step-1)
    for i in range(len(cards)):
        if i == 0:
            if sorted_cards[i] + fact > sorted_cards[i + 1] and sorted_cards[i] < fact:
                index_to_remove = i
                break
        elif i == len(cards) - 1:
            if sorted_cards[i] - fact < sorted_cards[i - 1] and sorted_cards[i] > fact * (step - 1):
                index_to_remove = i
                break
        else:
            if sorted_cards[i] - fact < sorted_cards[i - 1] and sorted_cards[i] + fact > sorted_cards[i + 1]:
                index_to_remove = i
                break
    removed_element = sorted_cards.pop(index_to_remove)
    magic_number = removed_element % fact
    set_magic_number(sorted_cards, magic_number)
    return (removed_element, sorted_cards)

def guess_missing(cards):
    """
    Guess the missing card.
    O(n^3) (because of compute_combination)
    """
    magic_number = get_magic_number(cards)
    step = len(cards)+1
    for i in range(step):
        potential =  i * factorial(step-1) + magic_number
        if potential not in cards:
            (computed, _) = compute_combination(cards+[potential])
            if potential == computed:
                return potential

if __name__ == "__main__":
    first = sys.stdin.readline()
    (s_nb_enc, s_nb_dec) = first.split()
    (nb_enc, nb_decode) = (int(s_nb_enc), int(s_nb_dec))
    for i in range(nb_enc):
        str_in = sys.stdin.readline().split()
        out_list = compute_combination([int(s) for s in str_in])[1]
        for out in out_list:
            print out,
        print 
    for i in range(nb_decode):
        str_in = sys.stdin.readline().split()
        print guess_missing([int(s) for s in str_in])
