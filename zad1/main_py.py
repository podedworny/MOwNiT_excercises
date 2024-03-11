from mpmath import mp

mp.dps = 100

def recursive_function_f(k, c):
    if tab[k] != mp.mpf('0'):
        return tab[k]
    tab[k] = (mp.mpf('10')/c) * recursive_function_f(k - 1, c) - recursive_function_f(k - 2, c)
    return tab[k]

def recursive_function_fb(k, c):
    if tab1[k] != mp.mpf('0'):
        return tab1[k]
    tab1[k] = (mp.mpf('10')/c) * recursive_function_fb(k + 1, c) - recursive_function_fb(k + 2, c)
    return tab1[k]


if __name__ == "__main__":
    c = mp.mpf('30')
    tab = [mp.mpf('0')] * 47
    tab[0] = mp.mpf('1')
    tab[1] = mp.mpf('1') / c
    
    recursive_function_f(46, c)
    
    tab1 = [mp.mpf('0')] * 47
    tab1[45] = tab[45]
    tab1[46] = tab[46]
    
    recursive_function_fb(0, c)
    
    for i in tab:
        print(i)
        
    print('\n\n')
    
    for i in tab1:
        print(i)