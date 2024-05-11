import random as r
def juntarListas(lista1, lista2, contador, listaNueva, index=0):
    '''
    E: Sus parámetros son las 2 listas que se juntarán, un contador que es la cantidad de elementos que tendrá la listaNueva, la listaNueva que cuando se llama a la función es [], y un index que es 0 por default.
    S: Junta 2 listas de la siguiente forma --> ["lista1[w] lista2[x]", "lista1[y] lista2[z]"...] con w x y z siendo valores random
    '''
    if contador != index:
        listaNueva += [lista1[r.randint(0,len(lista1) - 1)] + " " + lista2[r.randint(0,len(lista2) - 1)]]
        return juntarListas(lista1, lista2, contador, listaNueva, index + 1)
    else:
        return listaNueva


def crearlistaPrincipal(nombresAreas, nombresPersonas, numAreas, numPersonas):
    '''
    E: la lista con los nombres de las áreas, la lista con los nombres de las personas y la cantidad de áreas y personas.
    S: Retorna una lista de la forma [[lugar1,[personas en lugar1]],[lugar2,[personas en lugar2]]...]
    Nota: En caso de haber más personas que áreas, se dividirán las personas equivalentemente entre todas las áreas y las sobrantes irán a los primeros elementos de la lista
        Y en caso contrario, de haber más áreas que personas, las personas irán a las primeras áreas.
    '''
    listaNueva = EsqueletoListaPrincipal(nombresAreas, numAreas)
    if numPersonas // numAreas > 0:  #Si hay suficientes personas como para tener minimo una en cada area
        listaNueva = DividirPersonasEquivalentemente(nombresPersonas, numAreas,numPersonas // numAreas, listaNueva)
        DividirPersonasSobrantes(nombresPersonas[numAreas * (numPersonas // numAreas):], listaNueva)
    else:
        DividirPersonasSobrantes(nombresPersonas[numAreas * (numPersonas // numAreas):], listaNueva)
    return listaNueva


def EsqueletoListaPrincipal(nombresAreas,numAreas,listaNueva=[],index=0):  
    '''
    E: La lista con los nombres de las áreas y el número de áreas, además una lista que es vacía por default y un indice que es 0 por default
    S: Retorna una lista de la forma --> [[lugar1,[]], [lugar2,[]]...]
    '''
    if index == numAreas:
        return listaNueva
    else:
        listaNueva += [[nombresAreas[index]] + [[]]]
        return EsqueletoListaPrincipal(nombresAreas, numAreas, listaNueva,index + 1)


def DividirPersonasEquivalentemente(nombresPersonas,numAreas,contador,listaNueva,j=0, i=0): #Hace que cada area tenga la misma cantidad de personas como minimo. 

    
    '''
    E: Las entradas son la lista con los nombres de personas, el número de áreas, el contador que es numPersonas//numAreas 
        , la lista que nos dió EsqueletoListaPrincipal, los índices j,i
        La i se usa para indexar a cada área.
        La j se usa para indexar a las personas dentro de cada área.
    S: divide equivalentemente a las personas en cada área, las que sobran no se meten, se meterán en DividirPersonasSobrantes.
        Las personas se meten en las listas vacías que devolvió EsqueletoListaPrincipal.
    '''
    if i == numAreas:
        return listaNueva
    elif j == contador:  #cuando j llega a la cantidad de personas que va a haber en todas las áreas
        return DividirPersonasEquivalentemente(nombresPersonas, numAreas, contador,listaNueva, 0, i + 1)
    else:
        listaNueva[i][1] += [nombresPersonas[0]]
        return DividirPersonasEquivalentemente(nombresPersonas[1:], numAreas, contador,listaNueva, j + 1, i)


def DividirPersonasSobrantes(nombresPersonas,listaNueva,index=0):  #Agrega personas que sobran
    '''
    E: la lista de las personas que sobraron (podría ser lista vacía desde el inicio), la lista que devolvió DividirPersonasEquivalentemente o de haber menos personas que lugares en un principio, la que devolvió EsqueletoListaPrincipal, un index que es 0 por default.
    S: Mete a la lista principal las personas sobrantes (en el caso que haya), en las primeras áreas.
    '''
    if nombresPersonas == []:
        return listaNueva
    else:
        listaNueva[index][1] += [nombresPersonas[0]]
        return DividirPersonasSobrantes(nombresPersonas[1:], listaNueva, index + 1)
