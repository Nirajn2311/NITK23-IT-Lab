import random
import time
from pathlib import Path

import matplotlib.pylab as plt
import numpy as np

from mcts import MCTS
from minimax import det_next_action_alpha_beta as det_minimax
from tic_tac_toe import TTT


def available_action(s):
    l = []
    for i in range(9):
        if s[i] == '_':
            l.append(i)
    return l


def auto_random(board):
    actions = available_action(board)
    return random.choice(actions)


def auto_minimax(board):
    return det_minimax(board)[0]


def auto_mcts(board):
    tmp = MCTS(board)
    tmp.mcts()
    return tmp.result_return()


def mean(l):
    return sum(l)/len(l)


mmm, rrr = 20, 10  # Match, Round
plt_fontsize = {'title': 'x-small',
                'legend': 5,
                'x_lbl': 'x-small',
                'y_lbl': 'x-small',
                'tick_lbl': 'xx-small'}
fig_dpi = 300  # size of output img
look_through = True

if not Path('output').exists():
    Path('output').mkdir()

save_route = 'output/winning_rate'
save_route += time.strftime('_%m%d_%H%M%S', time.localtime(time.time()))

fig, axes = plt.subplots(3, 2, dpi=fig_dpi)

with open(save_route + '.txt', 'w') as f:
    f.write('=== Settings ===\n')
    f.write(f'- Matchs, Rounds: {mmm}, {rrr}\n')
    f.write(f'- Look Through: {str(look_through)}\n')

# 1. Random vs Random ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_random(t.board)
                t.ai_input(v)
            else:
                v = auto_random(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE I. Random VS Random\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')

ax0 = axes[0, 0]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X) = RANDOM')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O) = RANDOM')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'Random(P1, X) vs Random(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])
if look_through:
    time.sleep(3)


# 2. Minimax vs MCTS ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_minimax(t.board)
                t.ai_input(v)
            else:
                v = auto_mcts(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE II. Minimax VS MCTS\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')

ax0 = axes[0, 1]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X)=MINIMAX')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O)=MCTS')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'MINIMAX(P1, X) vs MCTS(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])


# 3. Random vs Minimax ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

mcts_iter_game, mcts_iter_round = [], []
mcts_iter_match = []*mmm

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_random(t.board)
                t.ai_input(v)
            else:
                v = auto_minimax(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE III. Random VS Minimax\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')

ax0 = axes[1, 0]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X)=RANDOM')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O)=MINIMAX')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'Random(P1, X) vs Minimax(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])
if look_through:
    time.sleep(3)


# 4. Minimax vs Random ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

mcts_iter_game, mcts_iter_round = [], []
mcts_iter_match = []*mmm

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_minimax(t.board)
                t.ai_input(v)
            else:
                v = auto_random(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE IV. Minimax VS Random\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')

ax0 = axes[1, 1]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X)=MINIMAX')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O)=RANDOM')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'Minimax(P1, X) vs Random(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])
if look_through:
    time.sleep(3)


# 5. Random vs MCTS ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_random(t.board)
                t.ai_input(v)
            else:
                v = auto_mcts(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE V. Random VS MCTS\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')

ax0 = axes[2, 0]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X)=RANDOM')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O)=MCTS')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'Random(P1, X) vs MCTS(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])
if look_through:
    time.sleep(3)


# 6. MCTS VS Random ===============================================
p1_data, p2_data, tie_data = [], [], []
p1_wins, p2_wins, tie = 0, 0, 0
iterations = np.arange(rrr, mmm * rrr + 1, rrr)

time_start = time.time()
for i in range(mmm):
    for j in range(rrr):
        t = TTT()
        if look_through:
            t.dispboard()
            print()
        while t.result == 0:
            if t.player == 1:
                v = auto_mcts(t.board)
                t.ai_input(v)
            else:
                v = auto_random(t.board)
                t.ai_input(v)
            if look_through:
                t.dispboard()
                print()
            t.checkresult()
            t.switch_player()
        r = t.result
        if look_through:
            print(f'\n{i+1}/{mmm}, {j+1}/{rrr}, {r}\n\n')
        if r == 1:
            p1_wins += 1
        elif r == 2:
            p2_wins += 1
        else:
            tie += 1
    p1_data.append(p1_wins / iterations[i] * 100)
    p2_data.append(p2_wins / iterations[i] * 100)
    tie_data.append(tie / iterations[i] * 100)

time_elapsd = round(time.time() - time_start, 3)
print('Elapsed Time: ', time_elapsd)
print('P1 winning rate: ', p1_data[-1])
print('P2 winning rate: ', p2_data[-1])
print()

with open(save_route + '.txt', 'a') as f:
    f.write('CASE VI. MCTS VS Random\n')
    f.write(f'- P1 final winning rate: {round(p1_data[-1],4)}%\n')
    f.write(f'- P2 final winning rate: {round(p2_data[-1],4)}%\n')
    f.write(f'- Elapsed Time: {time_elapsd}s\n\n')
    f.write(time.ctime())

ax0 = axes[2, 1]
ax0.grid(True)
ax0.plot(iterations, p1_data, 'r', lw=3, label='P1(X)=MCTS')
ax0.plot(iterations, p2_data, 'b', lw=3, label='P2(O)=Random')
ax0.plot(iterations, tie_data, 'g', lw=2, label='Tie')
ax0.set_xlabel('TicTacToe Rounds', fontsize=plt_fontsize['x_lbl'])
ax0.set_ylabel('Cumulative winning rate (%)', fontsize=plt_fontsize['y_lbl'])
ax0.tick_params(labelsize=plt_fontsize['tick_lbl'])
ax0.set_xlim(rrr, mmm*rrr)
ax0.set_ylim(-1, 101)
title_txt = 'MCTS(P1, X) vs Random(P2, O)'
ax0.set_title(title_txt, fontsize=plt_fontsize['title'], weight='bold')
ax0.legend(fontsize=plt_fontsize['legend'])
if look_through:
    time.sleep(3)

# =================================================
plt.tight_layout()
plt.savefig(save_route + '.jpg')
plt.show()
