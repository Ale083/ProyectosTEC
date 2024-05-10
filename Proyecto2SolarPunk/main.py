import random as r  #en vez de por ejemplo poner random.randint se pone r.randint
from funcionesNoRelacionadas import *
import os
import time

def main():
    #mezcla de nombres para los personajes
    nombres = [
        "Lucía", "Juan", "María", "Carlos", "Ana", "Pedro", "Laura", "Diego","Sofía", "Javier", "Valentina", "Miguel", "Paula", "Sebastián", "Andrea", "José", "Elena", "Gabriel", "Isabella", "Daniel"
    ]
    apellidos = [
        "García", "Fernández", "López", "Martínez", "González", "Rodríguez","Pérez", "Sánchez", "Ramírez", "Torres", "Flores", "Vásquez", "Ruiz","Díaz", "Alvarez", "Gómez", "Romero", "Hernández", "Jiménez", "Moreno"
    ]
    
    #mezcla de nombres para las áreas
    primerosNombres = [
        "Parque", "Jardín", "Bosque", "Plaza", "Paseo", "Arboreto", "Sendero","Mirador", "Pulmón", "Rincón", "Orilla", "Vereda", "Oasis", "Colina","Pradera", "Río", "Balcón", "Cascada", "Ladera", "Reserva"
    ]
    segundosNombres = [
        "Primavera", "Encantado", "Alegre", "Sombra", "Fresco", "Tranquilo","Silvestre", "Esmeralda", "Susurro", "Sereno", "Encanto", "Armonía","Cristal", "Eterno", "Cálido", "Aguamarina", "Brisa", "Luminoso", "Floreciente", "Serenidad"
    ]

    #bienvenida
    print("Bienvenido al juego HABLANDO CON TU SOLAR PUNK. En este juego, vas a poder escoger entre 1-100 áreas verdes y 2-200 personas. Para jugar, tendrás que escoger una de las áreas verdes y podrás interactuar con los personajes que te interesen dentro de ellas. Que disfrutes el juego!") 
    print(r'''
             .-.                                    ,-.
          .-(   )-.                              ,-(   )-.
         (     __) )-.                        ,-(_      __)
          `-(       __)                      (_    )  __)-'
            `(____)-',                        `-(____)-'
          - -  :   :  - -
              / `-' \
            ,    |   .
                 .                         _
                                          >')
                       _   /              (\\         (W)
                      =') //               = \     -. `|'
                       ))////)             = ,-      \(| ,-
                      ( (///))           ( |/  _______\|/____
        ~~~~~~~~~~~~~~~`~~~~'~~~~~~~~~~~~~\|,-'::::::::::::::
                    _                 ,----':::::::::::::::::
                 {><_'c   _      _.--':MJP:::::::::::::::::::
        __,'`----._,-. {><_'c  _-':::::::::::::::::::::::::::
        :.:.:.:.:.:.:.\_    ,-'.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:
        .:.:.:.:.:.:.:.:`--'.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.
        .....................................................
    ''')
    
    numAreas = input("Cuantas áreas verdes quieres generar?")
    if not esDigito(numAreas):
        print("Error, El caracter o caracteres ingresados no son un número")
        return None
    numAreas = int(numAreas)
    if numAreas < 1 or numAreas > 100:
        print("Error, el límite de áreas verdes es de 1-100")
        return None
    nombresAreas = juntarListas(primerosNombres, segundosNombres, numAreas, [])

    numPersonas = input("Cuantas personas quieres generar?")
    if not esDigito(numPersonas):
        print("Error, El caracter o caracteres ingresados no son un número")
        return None
    numPersonas = int(numPersonas)
    if numPersonas < 2 or numPersonas > 200:
        print("Error, el límite de personas es de 2-200")
        return None
    nombresPersonas = juntarListas(nombres, apellidos, numPersonas, [])

    listaPrincipal = crearlistaPrincipal(nombresAreas, nombresPersonas, numAreas, numPersonas)
    Inicio(listaPrincipal)

def Inicio(listaPrincipal):
    os.system('clear')
    printMapa(len(listaPrincipal), listaPrincipal)
    queAreaVisitar(listaPrincipal, len(listaPrincipal))


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
    #TODO: cambiar nombre a algo que tenga más sentido
    '''
    E: la lista de las personas que sobraron (podría ser lista vacía desde el inicio), la lista que devolvió DividirPersonasEquivalentemente o de haber menos personas que lugares en un principio, la que devolvió EsqueletoListaPrincipal, un index que es 0 por default.
    S: Mete a la lista principal las personas sobrantes (en el caso que haya), en las primeras áreas.
    '''
    if nombresPersonas == []:
        return listaNueva
    else:
        listaNueva[index][1] += [nombresPersonas[0]]
        return DividirPersonasSobrantes(nombresPersonas[1:], listaNueva, index + 1)


def printMapa(numAreas, listaPrincipal): #dice cuantas personas hay en cada area
    print("Las siguientes son las áreas verdes creadas:")
    printMapaAux(numAreas, listaPrincipal)


def printMapaAux(numAreas, listaPrincipal, index=0):
    if numAreas == index:
        return None

    print(
        f"{index}) {listaPrincipal[index][0]} --> {len(listaPrincipal[index][1])} persona(s)"
    )  #[input]. [área] --> N Personas
    printMapaAux(numAreas, listaPrincipal, index + 1)


def queAreaVisitar(listaPrincipal, numAreas):
    areaAVisitar = input(
        f"\nCual área verde quieres visitar? [0,{numAreas-1}]")
    if not esDigito(areaAVisitar):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(2)
        Inicio(listaPrincipal)
    areaAVisitar = int(areaAVisitar)
    if areaAVisitar < 0 or areaAVisitar >= numAreas:
        print("Error, no es un número valido")
        time.sleep(2)
        Inicio(listaPrincipal)
    visitarArea(listaPrincipal[areaAVisitar], listaPrincipal)


#[[lugar1,[personas en lugar1]],[lugar2,[personas en lugar2]]...]


def visitarArea(listaArea, listaPrincipal):
    os.system('clear')
    if listaArea[1] == []: #si no hay personas en el área
        AreaVacia(listaArea, listaPrincipal)
    printPersonasEnArea(listaArea)
    quePersonaHablar(listaArea, listaPrincipal)

def AreaVacia(listaArea, listaPrincipal):
    actividadesSolitarias()
    opcion = input(f"Se siente muy solo por aquí, que quieres hacer?")
    if not esDigito(opcion):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(2)
        AreaVacia(listaArea,listaPrincipal)
    opcion = int(opcion)
    if opcion < 0 or opcion > 5:
        print("Error, no es un número valido")
        time.sleep(2)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 0: #gritar
        print("AAAAAAAAAAAAAAA")
        time.sleep(1)
        print("Nadie parece escucharte aquí...")
        time.sleep(2)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 1: #hacer pregunta
        print("Que quieres preguntar?")
        noImporta = input()
        print("No hay nadie, a quien le hablas?")
        time.sleep(3)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 2: #jugar solitario
        print("Te pusiste a jugar solitario")
        time.sleep(3)
        if r.randint(0,1) == 0: #50%
            print("Perdiste")
        else:
            print("Ganaste")
        time.sleep(1)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 3: #Pensar
        print("...")
        time.sleep(3)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 4:
        print(r'''
                                          ██████████                            
                                    ██████░░░░░░░░░░██████                      
                                ████░░░░░░░░░░░░░░░░░░░░░░██████                
                            ████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒████            
                          ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██          
                        ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██        
                      ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██      
                      ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██      
                    ██░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░░░░██    
                    ██░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒████░░░░░░██    
                  ██░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░██  
                  ██░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░██  
                  ██░░░░██░░░░██████████░░░░░░░░░░░░░░████████████░░░░██░░░░██  
                ██░░░░░░░░░░██████████████░░░░░░░░░░████████████████░░░░░░░░░░██
                ██░░░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░░░██
                ██░░░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░░░██
                ██░░░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░░░██
                ██░░░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░░░██
                ██░░░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░░░██
                  ██░░░░░░░░░░▒▒▒▒▒▒░░░░░░░░██████░░░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░██  
                  ██░░░░░░░░░░▒▒▒▒▒▒░░░░░░██      ██░░░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░██  
                  ██░░░░░░░░░░▒▒▒▒▒▒░░░░██          ██░░░░▒▒▒▒▒▒▒▒░░░░░░░░░░██  
                    ██░░░░░░░░▒▒▒▒▒▒░░░░██          ██░░░░▒▒▒▒▒▒▒▒░░░░░░░░██    
                    ██░░░░░░░░▒▒▒▒▒▒░░░░██▓▓▓▓▓▓▓▓▓▓██░░░░▒▒▒▒▒▒▒▒░░░░░░░░██    
                    ░░██░░░░░░▒▒▒▒▒▒░░░░██▓▓▓▓▓▓▓▓▓▓██░░░░▒▒▒▒▒▒▒▒░░░░░░▓▓░░    
                      ██░░░░░░▒▒▒▒▒▒░░░░██▓▓▓▓▓▓▓▓▓▓██░░░░▒▒▒▒▒▒▒▒░░░░░░██      
                        ██░░░░▒▒▒▒▒▒░░░░░░██▓▓▓▓▓▓██░░░░░░▒▒▒▒▒▒▒▒░░░░██        
                          ██░░▒▒▒▒▒▒░░░░░░░░██████░░░░░░░░▒▒▒▒▒▒▒▒░░██          
                            ████▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒████            
                                ████░░░░░░░░░░░░░░░░░░░░░░████▓▓                
                                    ██████░░░░░░░░░░██████                      
                                          ██████████                            

        ''')
        time.sleep(3)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 5: #Si quiere salir
        time.sleep(2)
        Inicio(listaPrincipal)

def actividadesSolitarias():
    os.system('clear')
    print("0) Gritar")
    print("1) Preguntar")
    print("2) Jugar solitario")
    print("3) Pensar")
    print("4) Llorar")
    print("5) Salir")
    
def quePersonaHablar(listaArea, listaPrincipal):
    personaAHablar = input(
        f"\nCon que persona quieres hablar? [0,{len(listaArea[1])}]")
    if not esDigito(personaAHablar):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(3)
        return visitarArea(listaArea, listaPrincipal)
    personaAHablar = int(personaAHablar)
    if personaAHablar < 0 or personaAHablar > len(listaArea[1]):
        print("Error, no es un número valido.")
        time.sleep(3)
        return visitarArea(listaArea, listaPrincipal)
    if personaAHablar == len(listaArea[1]): #Si se selecciona la opción Salir
        time.sleep(2)
        print()
        Inicio(listaPrincipal)
    hablarPersona(listaArea[1][personaAHablar], listaArea[0],listaArea, listaPrincipal)


def hablarPersona(Persona, Area, listaArea, listaPrincipal): #listaArea solo se usa para salir
    #Respuestas que pueden dar los personajes al interactuar con el usuario
    Dialogos = [
        ["Qué le dice un techo a otro techo? Techo de menos. JAJAJA", "Por qué los pájaros no usan Facebook? Porque ya tienen Twitter. JAJAJ", "Qué hace una abeja en el gimnasio? Zum-ba! JAJAJ", "Qué le dice una iguana a su hermana gemela? Iguanita! JAJAJA", "Qué le dice una uva verde a una roja? Respira, respira! JAJAJA", "Cuál es el colmo de un electricista? Que su hijo sea un conductor. JAJAJ", "Por qué el libro de matemáticas está triste? Porque tiene demasiados problemas. JAJAJA", "Cómo se llama el campeón de buceo japonés? Tokofondo. JAJAJA", "Por qué los esqueletos no pelean entre sí? Porque no tienen agallas. JAJAJA", "Qué le dice una impresora a otra? Esa hoja es tuya o es una impresión mía? JAJAJA", "Qué hace una cama en el ejército? Se en-cama! JAJAJA", "Por qué los elefantes nunca olvidan? Porque siempre tienen en mente sus elefantásticas memorias. JAJAJ", "Cuál es el animal más conocido en la industria de la moda? El elefante, porque siempre lleva troncos a la pasarela! JAJAJA", "Cuál es el animal más alegre? El elefante, porque siempre anda con la trompa arriba! JAJAJA", "Por qué los elefantes son grises, grandes y arrugados? Porque si fueran blancos y pequeños, serían alka seltzer! JAJAJA", "Qué hace un elefante para esconderse de los depredadores? Se pone detrás de un árbol... pero a veces olvida lo grande que es y ¡sobresale un poco!", "Cómo cruzan los elefantes un río helado? En troncomóvil! JAJA", "Por qué los elefantes nunca juegan al póker en la selva? Porque hay demasiados tramposos con las trompas largas!", "Cómo puedes saber si un elefante ha estado en tu refrigerador? Por las huellas de sus patas en la mantequilla. JAJA"],  #chistes
        
        ["Sí, claro", "Jamás", "No sé", "Como gustes", "Piensalo un poco más", "Dejame pensarlo", "No te voy a responder", "Qué crees?", "Y esa pregunta?", "Estás bien?", "Es obvio", "Cómo no sabes eso?", "Crees que yo sé?"],  #Q&A
        
        ["Siento que vivo en el mundo perfecto", "Me encanta vivir acá", "Deberíamos hacer algo juntos", "Me encanta vivir aquí", "Amo pasear por mi pueblo", "Siempre pienso en lo diferente que es este lugar a como vivían mis antepasados", "Me encanta que todos nos ayudamos los unos a los otros."],  #SolarPunk
        
        [f"Amo vivir en {Area}","El día está muy soleado", "Estos árboles son hermosos", "El sol es muy brillante","Espero que no llueva", "Escucha los pájaros cantando", "El agua es muy fresca","Gracias nubes por la sombra", "Gracias árboles por la sombra", f"El río de {Area} me encanta"],  #Lugar
        
        ["El café es la segunda mercancía más comercializada en el mundo después del petróleo.", "Las ballenas azules, los mamíferos más grandes del planeta, tienen un corazón del tamaño de un automóvil pequeño y pueden escuchar el sonido de otros animales a miles de kilómetros de distancia.", "El alimento más consumido en el mundo es el arroz.", "En el antiguo Egipto, los gatos eran venerados como dioses y eran considerados protectores del hogar.", "Las avestruces pueden correr a una velocidad de hasta 70 km/h y son las aves más grandes y pesadas del mundo.", "El río Amazonas lleva más agua que los siguientes ocho ríos más grandes del mundo juntos.", "La Gran Muralla China es aproximadamente 13,170 millas de largo, lo suficientemente larga como para darle la vuelta al ecuador más de una vez.", "Las hormigas pueden transportar objetos que pesan hasta 50 veces su propio peso corporal.", "La Mona Lisa, pintada por Leonardo da Vinci, se exhibe en el Museo del Louvre en París y está protegida por una caja de vidrio que la mantiene a una temperatura constante y la protege de la luz ultravioleta.", "El sonido más fuerte producido por cualquier animal es el de la ballena azul, que puede llegar a 188 decibelios. Esto es más alto que un avión a reacción despegando."],  #Datazos
        
        ["Tengo hambre", f"Mi nombre es {Persona}", f"He vivido en {Area} desde que soy pequeñ@", "Tengo 5 hijos(as)", "Estoy casado(a)", "Estoy soltero(a)", "Tengo un perro", "Tengo un gato","Amo los animales", "De pequeño quería ser bombero", "De pequeño quería ser policía", "De pequeño quería ser militar", "Amo el café", "Amo la naturaleza", "Amo la música", "Me gusta bailar", "Mi animal favorito es el capibara"],  #Personal
        
        ["Te echaré de menos :(", "Te veo luego.", "Hasta pronto.", "Hasta luego, ¡cuídate!", "Nos vemos pronto. ¡Adiós!", "Fue genial verte. ¡Hasta la próxima!", "Que tengas un buen día. ¡Hasta luego!", "Adiós por ahora, ¡que todo vaya bien!", "Nos hablamos más tarde. ¡Hasta pronto!", "Que tengas un buen viaje. ¡Adiós!", "¡Cuídate mucho! Nos vemos pronto.", "Hasta la próxima vez. ¡Cuidate!", "Suerte haciendo amigos nuevos", "Adiós, ¡que tengas un buen día!"]  #Salir
    ]
    
    printOpciones()
    opcion = input(f"De qué quieres hablar con {Persona}?[0-6]\n")
    


    if not esDigito(opcion):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(2)
        hablarPersona(Persona, Area, listaArea, listaPrincipal)
    opcion = int(opcion)
    if opcion < 0 or opcion > 6:
        print("Error, no es un número valido")
        time.sleep(2)
        hablarPersona(Persona, Area, listaArea, listaPrincipal)

    if opcion == 0 or opcion == 2 or opcion == 3 or opcion == 4 or opcion == 5:
        dialogo = Dialogos[opcion][r.randint(0, len(Dialogos[opcion]) - 1)]
        print(dialogo)
        time.sleep(5)
        os.system('clear')
        hablarPersona(Persona,Area,listaArea, listaPrincipal)
    if opcion == 1:
        print("Claro! Que duda tienes?")
        noImporta = input()
        print(Dialogos[opcion][r.randint(0, len(Dialogos[opcion]) - 1)])
        time.sleep(4)
        hablarPersona(Persona,Area, listaArea, listaPrincipal)
    if opcion == 6: #si quiere salir de hablar con el personaje
        print(Dialogos[opcion][r.randint(0, len(Dialogos[opcion]) - 1)])
        print()
        time.sleep(3)
        visitarArea(listaArea, listaPrincipal)

def printPersonasEnArea(listaArea):
    os.system('clear')
    print(f"En {listaArea[0]} están las siguientes personas")
    printPersonasEnAreaAux(listaArea, len(listaArea[1]))
    

def printPersonasEnAreaAux(listaArea, personasEnArea, index=0):
    if personasEnArea == index:
        print(f"{personasEnArea}) Salir")
        return None
    print(f"{index}) {listaArea[1][index]}")
    return printPersonasEnAreaAux(listaArea, personasEnArea, index + 1)
    #[lugar1,[personas en lugar1]]

def printOpciones(): #printea las opciones para hablar con el personaje
    os.system('clear')
    print('0) "Cuentame un chiste!"')
    print('1) "Puedo hacerte una pregunta?"')
    print('2) "Qué piensas sobre este futuro?"')
    print('3) "Cuentame sobre este lugar!"')
    print('4) "Dime algun dato"')
    print('5) "Cuentame sobre ti!"')
    print('6) Salir del menú')

main()

