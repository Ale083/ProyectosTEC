import random as r  #en vez de por ejemplo poner random.randint se pone r.randint
from funcionesNoRelacionadas import *
from creacionDeListas import *
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
    os.system('clear')
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
    
    #Generación de la lista con las áreas verdes
    numAreas = input("Cuantas áreas verdes quieres generar?")
    if not esDigito(numAreas):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(2)
        return main()
    numAreas = int(numAreas)
    if numAreas < 1 or numAreas > 100:
        print("Error, el límite de áreas verdes es de 1-100")
        time.sleep(2)
        return main()
    nombresAreas = juntarListas(primerosNombres, segundosNombres, numAreas, [])

    #Generación de la lista con las personas
    numPersonas = input("Cuantas personas quieres generar?")
    if not esDigito(numPersonas):
        print("Error, El caracter o caracteres ingresados no son un número")
        time.sleep(2)
        return main()
    numPersonas = int(numPersonas)
    if numPersonas < 2 or numPersonas > 200:
        print("Error, el límite de personas es de 2-200")
        time.sleep(2)
        return main()
    nombresPersonas = juntarListas(nombres, apellidos, numPersonas, [])

    #creación de la lista principal
    listaPrincipal = crearlistaPrincipal(nombresAreas, nombresPersonas, numAreas, numPersonas)

    Inicio(listaPrincipal)

def Inicio(listaPrincipal):
    '''
    E: Tiene como entrada la lista principal
    S: Llama a printMapa() y a queAreaVisitar()
    '''
    os.system('clear')
    printMapa(len(listaPrincipal), listaPrincipal)
    queAreaVisitar(listaPrincipal, len(listaPrincipal))


def printMapa(numAreas, listaPrincipal): 
    '''
    E: Tiene como entrada el número de áreas y la lista principal
    S: Muestra al usuario los lugares a los que puede ir y las personas en cada uno
    '''
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
    '''
    E: Tiene como entradas la lista principal y el número de áreas
    S: Le pregunta al usuario cual área verde quiere visitar, si no da una respuesta válida lo devuelve a la última sección, llamando a la función Inicio()
       de dar una respuesta válida, llama a la función VisitarArea() 
    '''
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


def visitarArea(listaArea, listaPrincipal):
    '''
    E: Tiene como entradas, la lista del área, la cual es la lista que se ve: [áreaX,[personasEnElÁrea]] y también la lista principal
       que solo es usada si el usuario decide ir a la sección anterior
    S: Revisa si en el área escogida hay personas, si no hay personas entonces llama a la función AreaVacia().
       De lo contrario llama a printPersonasEnArea() y quePersonaHablar()
    '''
    os.system('clear')
    if listaArea[1] == []: #si no hay personas en el área
        AreaVacia(listaArea, listaPrincipal)
    else:
        printPersonasEnArea(listaArea)
        quePersonaHablar(listaArea, listaPrincipal)

def AreaVacia(listaArea, listaPrincipal):
    '''
    E: Tiene como entradas, la lista del área, la cual es la lista que se ve: [áreaX,[personasEnElÁrea]] y también la lista principal
       que solo es usada si el usuario decide ir a la sección anterior.
    S: Muestra al usuario las actividades que puede hacer en un área sin personas, le pregunta que quiere hacer y dependiendo de la opción escogida se imprimen diferentes cosas, luego se llama a la misma función de nuevo.
       Si el usuario quiere volver a la sección anterior puede escoger SALIR y se llama a la función Inicio()
    '''
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
        print(r'''
                  _____
                 |A .  | _____
                 | /.\ ||A ^  | _____
                 |(_._)|| / \ ||A _  | _____
                 |  |  || \ / || ( ) ||A_ _ |
                 |____V||  .  ||(_'_)||( v )|
                        |____V||  |  || \ / |
                               |____V||  .  |
                                      |____V|
        ''')
        time.sleep(3)
        if r.randint(0,1) == 0: #50%
            print("Perdiste")
        else:
            print("Ganaste")
        time.sleep(1)
        AreaVacia(listaArea,listaPrincipal)
    if opcion == 3: #Pensar
        print(r'''
        ⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠚⠉⠉⠉⠓⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⢠⠋⠀⠀⠀⠀⠀⠀⠀⠙⣆⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⢀⣠⠤⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⢄⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⡴⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠒⠒⠦
        ⠀⢀⡸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆
        ⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸
        ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞
        ⠹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡠⠴⠋⠀
        ⠀⠈⠓⠒⠒⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⢠⠚⠉⢪⠓⠦⢄⣀⠤⠴⠒⠦⣄⣀⠀⢀⣀⡤⠖⠀⠀⠀⠀⠀⠀
        ⠀⢀⡤⣜⢦⣠⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⣠⣾⢲⠚⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ''')
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
    '''
    E: No tiene entradas
    S: Imprime las actividades que el usuario puede hacer en AreaVacia()
    '''
    os.system('clear')
    print("0) Gritar")
    print("1) Preguntar")
    print("2) Jugar solitario")
    print("3) Pensar")
    print("4) Llorar")
    print("5) Salir")
    

def printPersonasEnArea(listaArea):
    '''
    E: Tiene como parámetro la lista del Área
    S: Muestra al usuario las personas que hay en dicha área.
    '''
    os.system('clear')
    print(f"En {listaArea[0]} están las siguientes personas")
    printPersonasEnAreaAux(listaArea, len(listaArea[1]))

def printPersonasEnAreaAux(listaArea, personasEnArea, index=0):
    if personasEnArea == index:
        print(f"{personasEnArea}) Salir")
        return None
    print(f"{index}) {listaArea[1][index]}")
    return printPersonasEnAreaAux(listaArea, personasEnArea, index + 1)


def quePersonaHablar(listaArea, listaPrincipal):
    '''
    E: Tiene como entradas, la lista del área, la cual es la lista que se ve: [áreaX,[personasEnElÁrea]] y también la lista principal
       que solo es usada si el usuario decide ir a la sección anterior
    S: Pregunta al usuario con que persona del área quiere hablar, si da una respuesta invalida llama VisitarArea()
       si selecciona la opción SALIR, lo devuelve a la sección anterior llamando Inicio()
       si escoge un número valido que no sea SALIR, llama a la función hablarPersona()
    '''
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
    else:
        hablarPersona(listaArea[1][personaAHablar], listaArea[0],listaArea, listaPrincipal)


def hablarPersona(Persona, Area, listaArea, listaPrincipal): 
    '''
    E: Tiene como entradas el nombre de la persona con la que se está interactuando, el área en donde se encuentra.
       la Lista del Area y la lista principal son solo usadas en el caso que se quiera volver a la sección anterior, pues son parámetros de las funciones anteriores.
    S: Pregunta al usuario de que quiere hablar con la persona, responde según lo escogido y vuelve a llamar a hablarPersona para seguir el dialogo.
       Si el usuario escoge SALIR, vuelve a la sección anterior llamando visitarArea()
    '''
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
        time.sleep(3)
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


def printOpciones(): 
    '''
    E: No tiene entradas
    S: Muestra al usuario las opciones de dialogo con el personaje
    '''
    os.system('clear')
    print('0) "Cuentame un chiste!"')
    print('1) "Puedo hacerte una pregunta?"')
    print('2) "Qué piensas sobre este futuro?"')
    print('3) "Cuentame sobre este lugar!"')
    print('4) "Dime algun dato"')
    print('5) "Cuentame sobre ti!"')
    print('6) Salir del menú')

main()

