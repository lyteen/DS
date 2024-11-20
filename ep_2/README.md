# **Function Readme**

main function in `hfmT.cc`

1. **CreateHfmTree**
    - `Work` Create the HFM-Tree
    - `Args` chars: Node name, w: Node weight
    - `Return` hfmTNode *

2. **PrintHfmTree**
    - `Work` Print HFM-Tree
    - `Args` root: hfm-tree root location
    - `Return` None

3. **generateCode**
    - `Work` generate HFM encode
    - `Args` root: hfm-tree root location, codes: store hfm encode, str: str output prefix
    - `Return` None

4. **PrintCodes**
    - `Work` Print the HFM-Code e.g. a->1001
    - `Args` code: HFM-Code
    - `Return` None

5. **Decode**
    - `Work` Decode the HFM Code to str e.g. 1001->a
    - `Args` root: HFM-Tree, str: HFM-Code
    - `Return` None