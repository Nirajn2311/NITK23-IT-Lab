import random
import time
from pathlib import Path

import matplotlib.pylab as plt

from mcts import MCTS
from minimax import det_next_action_alpha_beta as det_minimax
from tic_tac_toe import TTT


def auto_mcts(board, mode, criteria):
    tmp = MCTS(board)
    iii = tmp.mcts(mode=mode, criteria=criteria)
    return iii, tmp.result_return()


mcts_criteria_0 = ['time', 100]
fig_dpi = 200
p1_iter, p2_iter = [], []
p1_turn, p2_turn = [], []
turns = 1

t = TTT()
t.dispboard()
print()
while t.result == 0:
    if t.player == 1:
        iterations, v = auto_mcts(t.board, mcts_criteria_0[0], mcts_criteria_0[1])
        p1_iter.append(iterations)
        p1_turn.append(turns)
        turns += 1
        t.ai_input(v)
    else:
        iterations, v = auto_mcts(t.board, mcts_criteria_0[0], mcts_criteria_0[1])
        p2_iter.append(iterations)
        p2_turn.append(turns)
        turns += 1
        t.ai_input(v)
    t.dispboard()
    print()
    t.checkresult()
    t.switch_player()

p1_iter_average = sum(p1_iter) / len(p1_iter)
p2_iter_average = sum(p2_iter) / len(p2_iter)

fig, axes = plt.subplots(2, 1, dpi=fig_dpi)

ax0 = axes[0]

ax0.set_title(f'MCTS iterations by time\n(Time Limit: {mcts_criteria_0[1]}ms)')
ax0.plot(p1_turn, p1_iter, lw=3, color='#1f77b4')
ax0.annotate(text=p1_iter[0], xy=(p1_turn[0], p1_iter[0]), color='b')
ax0.annotate(text=p1_iter[-1], xy=(p1_turn[-1], p1_iter[-1]), color='b')

ax0.plot(list(range(turns)), [p1_iter_average] * turns, '-.', color='#1f77b4')
ax0.annotate(text=round(p1_iter_average, 2), xy=(1, p1_iter_average), color='b')

ax0.plot(p2_turn, p2_iter, lw=3, color='#ff7f0e')
ax0.annotate(text=p2_iter[0], xy=(p2_turn[0], p2_iter[0]), color='r')
ax0.annotate(text=p2_iter[-1], xy=(p2_turn[-1], p2_iter[-1]), color='r')

ax0.plot(list(range(turns)), [p2_iter_average] * turns, '-.', color='#ff7f0e')
ax0.annotate(text=round(p2_iter_average, 2), xy=(turns - 2, p2_iter_average), color='r')

ax0.set_xlabel('Turns')
ax0.set_ylabel('Iterations')

mcts_criteria_1 = ['iter', int((p1_iter_average + p2_iter_average) / 2)]
p1_time, p2_time = [], []
p1_turn, p2_turn = [], []
turns = 1

t = TTT()
t.dispboard()
print()
while t.result == 0:
    if t.player == 1:
        time_start = time.time()
        iterations, v = auto_mcts(t.board, mcts_criteria_1[0], mcts_criteria_1[1])
        p1_time.append(time.time() - time_start)
        p1_turn.append(turns)
        turns += 1
        t.ai_input(v)
    else:
        time_start = time.time()
        iterations, v = auto_mcts(t.board, mcts_criteria_1[0], mcts_criteria_1[1])
        p2_time.append(time.time() - time_start)
        p2_turn.append(turns)
        turns += 1
        t.ai_input(v)
    t.dispboard()
    print()
    t.checkresult()
    t.switch_player()

p1_time_average = sum(p1_time) / len(p1_iter)
p2_time_average = sum(p2_time) / len(p2_iter)

ax0 = axes[1]
ax0.set_title(f'MCTS durations by iteration\n(Iteration limit: {mcts_criteria_1[1]}cycle)')

ax0.plot(p1_turn, p1_time, lw=3, color='#1f77b4')
ax0.annotate(text=round(p1_time[0], 3), xy=(p1_time[0], p1_time[0]), color='b')
ax0.annotate(text=round(p1_time[-1], 3), xy=(p1_turn[-1], p1_time[-1]), color='b')

ax0.plot(list(range(turns)), [p1_time_average] * turns, '-.', color='#1f77b4')
ax0.annotate(text=round(p1_time_average, 3), xy=(1, p1_time_average), color='b')

ax0.plot(p2_turn, p2_time, lw=3, color='#ff7f0e')
ax0.annotate(text=round(p2_time[0], 3), xy=(p2_turn[0], p2_time[0]), color='r')
ax0.annotate(text=round(p2_time[-1], 3), xy=(p2_turn[-1], p2_time[-1]), color='r')

ax0.plot(list(range(turns)), [p2_time_average] * turns, '-.', color='#ff7f0e')
ax0.annotate(text=round(p2_time_average, 3), xy=(turns - 2, p2_time_average), color='r')

ax0.set_xlabel('Turns')
ax0.set_ylabel('Time (s)')

plt.tight_layout()
if not Path('output').exists():
    Path('output').mkdir()
save_route = f'output/mcts_iter_time_relationship_{mcts_criteria_0[1]}'
save_route += time.strftime('_%m%d_%H%M%S', time.localtime(time.time()))
plt.savefig(save_route + '.jpg')
plt.show()
