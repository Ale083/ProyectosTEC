def crearMatrizCuadrada(largo):
    MatNueva = []
    for i in range(largo):
        MatNueva += [[]]
        for j in range(largo):
            MatNueva[i] += ["◼"]
    return MatNueva

tablero = crearMatrizCuadrada(7)

def printTablero(tablero,largo=0):
    largo = len(tablero)
    for k in range(largo):
        print("-----", end="")
    print("-")    
    for i in tablero:
        for j in i:
            print("|", end=" ")
            print(j, end="  ")
        print("|")
        print("-", end="")
        for k in range(largo):
            print("-----", end="")
        print()



printTablero(tablero)
