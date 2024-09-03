import time
def esDigito(input):
  '''
  E: la entrada del usuario al usar input, el cual será un string.
  S: un booleano, True si el string es un digito (y entero), False si no lo es.
  '''
  if not isinstance(input, str):
      return False
  if input == "":
      return False
  for i in input:
      if i == "0" or i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8" or i == "9":
          continue
      else:
          return False
  return True

def crearMatrizCuadrada(largo):
    '''
    E: El largo de la matriz cuadrada que se quiere crear.
    S: Retorna la matriz cuadrada con sus elementos siendo "◼", del largo del parámetro
    '''
    MatNueva = []
    for i in range(largo):
        MatNueva += [[]]
        for j in range(largo):
            MatNueva[i] += ["◼"]
    time.sleep(1)
    return MatNueva
    