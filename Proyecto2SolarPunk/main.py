import random as r #en vez de por ejemplo poner random.randint se pone r.randint
from funcionesNoRelacionadas import *

def main():
    nombres = [
        "Lucía", "Juan", "María", "Carlos", "Ana", "Pedro", "Laura", "Diego",
        "Sofía", "Javier", "Valentina", "Miguel", "Paula", "Sebastián",
        "Andrea", "José", "Elena", "Gabriel", "Isabella", "Daniel"
    ]
    apellidos = [
        "García", "Fernández", "López", "Martínez", "González", "Rodríguez",
        "Pérez", "Sánchez", "Ramírez", "Torres", "Flores", "Vásquez", "Ruiz",
        "Díaz", "Alvarez", "Gómez", "Romero", "Hernández", "Jiménez", "Moreno"
    ]
    primerosNombres = [
        "Parque", "Jardín", "Bosque", "Plaza", "Paseo", "Arboreto", "Sendero",
        "Mirador", "Pulmón", "Rincón", "Orilla", "Vereda", "Oasis", "Colina",
        "Pradera", "Río", "Balcón", "Cascada", "Ladera", "Reserva"
    ]
    segundosNombres = [
        "Primavera", "Encantado", "Alegre", "Sombra", "Fresco", "Tranquilo",
        "Silvestre", "Esmeralda", "Susurro", "Sereno", "Encanto", "Armonía",
        "Cristal", "Eterno", "Cálido", "Aguamarina", "Brisa", "Luminoso",
        "Floreciente", "Serenidad"
    ]
    print(
        "Bienvenido al juego HABLANDO CON TU SOLAR PUNK. En este juego, vas a poder escoger entre 1-100 áreas verdes y 2-200 personas. Para jugar, tendrás que escoger una de las áreas verdes y podrás interactuar con los personajes que te interesen dentro de ellas."
    )
    numAreas = input("Cuantas áreas verdes quieres generar")
    if not esDigito(numAreas):
        print("Error, el cáracter ingresado no es un número.")
        return None
    numAreas = int(numAreas)
    if numAreas <1 or numAreas >100:
        print("Error, el límite de áreas verdes es de 1-100")
        return None
    nombresAreas = juntarListas(primerosNombres, segundosNombres, numAreas, [])

    numPersonas = input("Cuantas personas quieres generar?")
    if not esDigito(numPersonas):
        print("Error, el cáracter ingresado no es un número.")
        return None
    numPersonas = int(numPersonas)
    if numPersonas <2 or numPersonas >200:
        print("Error, el límite de personas es de 2-200")
        return None
    nombresPersonas = juntarListas(nombres, apellidos, numPersonas, [])
    listaPrincipal = crearlistaPrincipal(nombresAreas, nombresPersonas, numAreas, numPersonas)
    printMapa(numAreas, listaPrincipal)

def juntarListas(lista1, lista2, contador, listaNueva, index=0):
    '''
    E: Sus parámetros son las 2 listas que se juntarán, un contador que es la cantidad de elementos que tendrá la listaNueva, la listaNueva que cuando se llama a la función es [], y un index que es 0 por default.
    S: Junta 2 listas de la siguiente forma --> ["lista1[w] lista2[x]", "lista1[y] lista2[z]"...] con w x y z siendo valores random
    '''
    if contador != index:
        listaNueva += [lista1[r.randint(0,len(lista1)-1)] + " " + lista2[r.randint(0,len(lista2)-1)]]
        return juntarListas(lista1, lista2, contador, listaNueva, index +1, )
    else: 
        return listaNueva

def crearlistaPrincipal(nombresAreas, nombresPersonas, numAreas, numPersonas):
    '''
    E: la lista con los nombres de las áreas, la lista con los nombres de las personas y los números de áreas y personas.
    S: Retorna una lista de la forma [[lugar1,[personas en lugar1]],[lugar2,[personas en lugar2]]...]
    Nota: En caso de haber más personas que áreas, se dividirán las personas equivalentemente entre todas las áreas y las sobrantes irán a los primeros elementos de la lista
        Y en caso contrario, de haber más áreas que personas, las personas irán a las primeras áreas.
    '''
    listaNueva = crearListaPrincipal1(nombresAreas,numAreas) 
    if numPersonas // numAreas >= 0: #Si hay suficientes personas como para tener minimo una en cada area
        listaNueva = crearListaPrincipal2(nombresPersonas, numAreas, numPersonas//numAreas, listaNueva)
        crearListaPrincipal3(nombresPersonas[numAreas*(numPersonas//numAreas):], listaNueva)
    else:
        crearListaPrincipal3(nombresPersonas[numAreas*(numPersonas//numAreas):], listaNueva)
    return listaNueva


def crearListaPrincipal1(nombresAreas, numAreas, listaNueva = [], index=0): #TODO: cambiar nombre a algo que tenga más sentido
    '''
    E: La lista con los nombres de las áreas y el número de áreas, además una lista que es vacía por default y un indice que es 0 por default
    S: Retorna una lista de la forma --> [[lugar1,[]], [lugar2,[]]...]
    '''
    if index == numAreas:
        return listaNueva
    else:
        listaNueva += [[nombresAreas[index]] + [[]]]
        return crearListaPrincipal1(nombresAreas, numAreas, listaNueva, index+1)
    

def crearListaPrincipal2(nombresPersonas, numAreas, contador, listaNueva,j=0, i=0): #TODO: cambiar nombre a algo que tenga más sentido
    '''
    E: Las entradas son la lista con los nombres de personas, el número de áreas, el contador que es numPersonas//numAreas 
        (la cantidad de personas que va a haber en cada área para este paso de dividir las personas equivalentemente entre las zonas.)
        , la lista que nos dió crearListaPrincipal1, los índices j,i
        La i se usa para indexar a cada área.
        La j se usa para indexar a las personas dentro de cada área.
    S: divide equivalentemente a las personas en cada área, las que sobran no se meten, se meterán en crearListaPrincipal3.
        Las personas se meten en las listas vacías que devolvió crearListaPrincipal1.
    '''
    if i == numAreas:
        return listaNueva
    elif j==contador: #cuando j llega a la cantidad de personas que va a haber en todas las áreas
        return crearListaPrincipal2(nombresPersonas, numAreas, contador, listaNueva, 0,i+1)
    else: 
        listaNueva[i][1] += [nombresPersonas[0]]
        return crearListaPrincipal2(nombresPersonas[1:], numAreas, contador, listaNueva, j+1, i)

def crearListaPrincipal3(nombresPersonas, listaNueva, index=0): #TODO: cambiar nombre a algo que tenga más sentido
    '''
    E: la lista de las personas que sobraron (podría ser lista vacía desde el inicio), la lista que devolvió crearListaPrincipal2 o de haber menos personas que lugares en un principio, la que devolvió crearListaPrincipal1, un index que es 0 por default.
    S: Mete a la lista principal las personas sobrantes (en el caso que haya), en las primeras áreas.
    '''
    if nombresPersonas == []:
        return listaNueva
    else:
        listaNueva[index][1] += [nombresPersonas[0]]
        return crearListaPrincipal3(nombresPersonas[1:], listaNueva, index+1)


def printMapa(numAreas,listaPrincipal):
    print("Las siguientes son las áreas verdes creadas:")
    printMapaAux(numAreas,listaPrincipal)
    
def printMapaAux(numAreas,listaPrincipal,index=0):
    if numAreas == index:
        return None
    print(f"{index}) {listaPrincipal[index][0]} --> {len(listaPrincipal[index][1])} persona(s)") #[input]. [área] --> N Personas
    printMapaAux(numAreas,listaPrincipal,index+1)

main()

#TODO validaciones