from tic_tac_toe import TTT
from copy import deepcopy
import time

winning_cases = [(0, 1, 2), (3, 4, 5), (6, 7, 8),
                 (0, 3, 6), (1, 4, 7), (2, 5, 8),
                 (0, 4, 8), (2, 4, 6)]


def minimax(s, p, depth=0):
    if terminal(s):
        return state_evaluation(s, p)
    cp = current_player(s)
    val = -2 if cp == p else 2
    actions = available_action(s)
    for a in actions:
        s_new = action_result(s, cp, a)
        v = minimax(s_new, p, depth + 1)
        val = max(val, v) if cp == p else min(val, v)
    return val


def minimax_alpha_beta(s, p, depth=0):
    if terminal(s):
        return state_evaluation(s, p)
    cp = current_player(s)
    val = -2 if cp == p else 2
    actions = available_action(s)
    for a in actions:
        s_new = action_result(s, cp, a)
        v = minimax(s_new, p, depth + 1)
        if v == -1 if cp*p == 2 else 1:
            val = v
            break
        val = max(val, v) if cp == p else min(val, v)
    return val


def det_next_action(s):
    p = current_player(s)
    if s == list('_' * 9):
        return 0
    elif '_' not in s:
        return None
    values = []
    actions = available_action(s)
    for a in actions:
        s_new = action_result(s, p, a)
        values.append(minimax(s_new, p))
    return actions[values.index(max(values))], list(zip(actions, values))


def disp_next_action(s):
    v = det_next_action(s)
    a, d = v
    d.append((9, 9))
    r, cnt = [], 0
    for i in range(9):
        if d[cnt][0] == i:
            r.append(str(d[cnt][1]))
            cnt += 1
        else:
            r.append('_')
    for i in range(3):
        print('\t'.join(r[3 * i:3 * (i + 1)]))
    print(f'Ideal action value: {a}')


def det_next_action_alpha_beta(s):
    p = current_player(s)
    if s == list('_' * 9):
        return 0, 0
    elif '_' not in s:
        return None, None
    values = []
    actions = available_action(s)
    for a in actions:
        s_new = action_result(s, p, a)
        values.append(minimax_alpha_beta(s_new, p))
    return actions[values.index(max(values))], list(zip(actions, values))


def disp_next_action_alpha_beta(s):
    a, d = det_next_action_alpha_beta(s)
    d.append((9, 9))
    r, cnt = [], 0
    for i in range(9):
        if d[cnt][0] == i:
            r.append(str(d[cnt][1]))
            cnt += 1
        else:
            r.append('_')
    for i in range(3):
        print('\t'.join(r[3 * i:3 * (i + 1)]))
    print(f'Ideal action value: {a}')


def current_player(s):
    n = s.count('_')
    if n % 2 == 1:
        return 1
    return 2


def available_action(s):
    l = []
    for i in range(9):
        if s[i] == '_':
            l.append(i)
    return l


def terminal(s):
    for wc in winning_cases:
        if s[wc[0]] != '_' and \
                s[wc[0]] == s[wc[1]] and \
                s[wc[1]] == s[wc[2]]:
            return True
    if '_' not in s:
        return True
    return False


def state_evaluation(s, p):
    p = 'X' if p == 1 else 'O'
    for wc in winning_cases:
        if s[wc[0]] != '_' and \
                s[wc[0]] == s[wc[1]] and \
                s[wc[1]] == s[wc[2]]:
            if s[wc[0]] == p:
                return 1
            else:
                return -1
    if '_' not in s:
        return 0


def action_result(s, p, a):
    new_s = deepcopy(s)
    new_s[a] = 'X' if p == 1 else 'O'
    return new_s


if __name__ == '__main__':
    t = TTT()
    while t.result == 0:
        t.dispboard()
        t.player_input()
        t.checkresult()
        t.switch_player()
        if t.result != 0:
            break

        print("Next desirable action without alpha-beta pruning")
        start_time = time.time()
        # v = det_next_action(t.board)
        # print(v[0])
        disp_next_action(t.board)
        print("Time taken", time.time()-start_time)
        print()
        print("Next desirable action with alpha-beta pruning")
        start_time = time.time()
        # v = det_next_action_alpha_beta(t.board)
        # print(v[0])
        disp_next_action_alpha_beta(t.board)
        print("Time taken", time.time()-start_time)
        print()

    t.dispboard()
    if t.result == 3:
        print('Game Tied')
    else:
        print(f'Player {t.result} Won!')
