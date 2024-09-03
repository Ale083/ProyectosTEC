import random
import time
import os
from Auxiliar import * #del archivo llamado Auxiliar, importar todo. Es como si tuvieramos el codigo aquí.


def Bienvenida(): 
  '''
  E: No tiene parámetros
  S: Imprime toda la bienvenida, incluyendo ASCII art y de que trata el juego
  '''
  print(r'''
    ____  _                           _     _       
   |  _ \(_)                         (_)   | |      
   | |_) |_  ___ _ ____   _____ _ __  _  __| | ___  
   |  _ <| |/ _ \ '_ \ \ / / _ \ '_ \| |/ _` |/ _ \ 
   | |_) | |  __/ | | \ V /  __/ | | | | (_| | (_) |
   |____/|_|\___|_| |_|\_/ \___|_| |_|_|\__,_|\___/ 
  ''')
  print(
"Bienvenido al juego SUSTENTA A TUS COMUNIDADES. En este juego usted tendrá un numero de comunidades con valores aleatorios de de Autonomía y Culturalidad. El objetivo de este juego es aumentar los niveles de la autonomia y la cultura de todas tus comunidades. Para ello, tendrás que hacer proyectos de autonomía y de cultura hasta llegar al nivel 9. Sin embargo, ultimamente han estado llegando amenazas y ataques de los mineros y misioneros diciendo que el terreno de tus comunidades es de ellos, lo cual baja los niveles de autonomía y cultura. Por cada nivel que sube tus comunidades los ataques harán más daño. Si alguna de tus comunidades llega a niveles de 0 en autonomía o cultura, perderás el juego. ¡Buena suerte!"
  )  #Presentación del juego

  print(r'''
                   ***          ***                     
                ***....**     **...***                  
               **........** **.......**                 
        ***    **..........*.........**    ***
     **.....**  **..................**  **.....**
   **.........**  **..............**  **.........**
  *..............*   *..........*   *..............*
   **..............*   *......*   *..............**
     **..............** *....* **..............**
       *......................................*
     **..............**........**..............**
   **..............*    *....*....*..............**
  *..............*    *........* ...*..............*
   **.........**    *............* ...**.........**
     **.....**   **...............**....**.....**
        ***    **...................**.....***
             **...........*...........**....*
              **.........* *.........** 
                *......**   **......*     
                  **  *       * **        
  ''')


def Main():
  Bienvenida()

  #definir valores predeterminados
  comunidades = ["Salitre", "Cabagra"]
  cultura = [random.randint(30, 40), random.randint(75, 90)]
  autonomia = [random.randint(30, 40), random.randint(75, 90)]
  niveles = [1, 3]
  colores = [["verde", "amarillo", "verde"], ["rojo", "amarillo"]]
  nivelMejoras = 1

  mas_comunidades = input("\nTu consejo trabajará con las comunidades de Salitre y Cabagra, quieres trabajar con más comunidades? [Si / No]\n"
  )  

  if mas_comunidades == "Si": #si se quiere jugar con más comunidades
    numero_comunidades = input("\nCon cuántas comunidades más deseas trabajar? [1-3]\n")
    if not esDigito(numero_comunidades):  #valida si lo que hay dentro del string es número y entero
      return print("Debe ser un número entero. Intenta de nuevo.")
    numero_comunidades = int(numero_comunidades)
    if numero_comunidades < 1 or numero_comunidades > 3: #valida que esté entre 1 y 3, ya sabiendo que es entero
      return print("Debe ser un número entre 1 y 3. Intenta de nuevo.")
    else:
      comunidades += AsignarNombresComunidades(numero_comunidades) #añadir a la lista de comunidades las nuevas.
      colores += AsignarColoresBandera(comunidades[2:])  #el [2:] para quitar salitre y cabagra de la lista, estos ya tienen banderas
      cultura += AsignarValorCultura(numero_comunidades) #añadir a la lista de cultura valores random para las nuevas comunidades
      autonomia += AsignarValorAutonomia(numero_comunidades)
      niveles += AsignarNiveles(numero_comunidades)

  elif mas_comunidades == "No":
    #no hace nada, ya creamos los valores para salitre y cabagra antes, no hay necesidad de más variables
    pass
  else:
    return print("Debe ser Si o No. Intenta de nuevo.")
  
  niveles = RevisarValoresNivel(cultura, autonomia)  #se llama a la función para actualizar los niveles de las comunidades.
  return print("Llegaste a", Ronda(comunidades, cultura, autonomia, niveles, colores, nivelMejoras), "rondas")



def Ronda(comunidades, cultura, autonomia, niveles, colores, nivelMejoras):
  Menu(comunidades, cultura, autonomia, niveles, colores,nivelMejoras)
  proyOMej = input("Quieres hacer un proyecto o mejorar el consejo (mejorando consigues más puntos al hacer proyectos) [1/2]\n")
  if proyOMej == "1":
    print("En que comunidad quieres hacer un proyecto?\n")
    comunidad = input()
    Proyecto(comunidades, cultura, autonomia, niveles, comunidad, nivelMejoras)
  elif proyOMej == "2":
     nivelMejoras = Mejora(nivelMejoras, niveles, comunidades)
  else:
    print("No es una opción válida. Pierdes el turno")
  Ataque(comunidades, cultura, autonomia, niveles)
  niveles = RevisarValoresNivel(cultura, autonomia)
  revisarNivelDeMejora(niveles, nivelMejoras)
  if revisarSiPerdio(comunidades, niveles):  #va a regresar true o false
    return 1
  if revisarSiGano(niveles):
    return 1
  else:
    return 1 + Ronda(comunidades, cultura, autonomia, niveles, colores, nivelMejoras)


  
Main()
