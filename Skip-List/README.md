# **README**

skip structure in `include\skipList.hpp`

## **Parameter**

- `val`: value of the node.
- `forward`: array of forward pointers at different levels. Like:
```
Node N(val = 5, forward.size = 3):
    forward[0] -> Node 1(val = 1) -> Node 2(val = 3) -> NULL
    forward[1] -> Node 3(val = 4) -> Node 4(val = 7) -> NULL
    forward[2] -> Node 5(val = 9) -> NULL
```
- `mt19937 generator`: generates pseudo-random numbers.
- `dis`: get the random number from (a, b)<double>
- `update`: array store each level of nodes that are closest to the insertion point. Example:
```
insertion = 40
curr -> forward[3] -> NULL
curr -> forward[2] -> val = 50 > 40
curr -> forward[1] -> val = 50 > 40
curr -> forward[0] -> val = 50 > 40
-> update[0] = curr
newNode(40, max(level, lv)):
    loop(lv--)
    {
        newNode -> forward[i] = update[i] -> forward[i]
        update[i] -> forward[i] = newNode
    } 
```

## **Function**

main function in `src\skipList.cc`

main idea:
![](reference\skip-list.gif)

1. **search**
    traverse from top to bottom level to search same size val node.
    `Args:` num: search num.
    `Return:` bool

2. **add**
    traverse from top to bottom level to find node val >= inserted value, then add it.
    `Args:` num: inserted num.
    `Return:` void

3. **erase**
    traverse from top to bottom level to get erased node previous node, then update the previous node point. 
    `Args:` num: inserted num.
    `Return:` void

4. **printNode**
    print head node from bottom level to top level.
    `Args:` NULL
    `Return:` void