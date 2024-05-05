def redondeoAbajo(num):
  return num - (num % 1)

def esDigito(input):
  '''
  E: la entrada del usuario al usar input, el cual será un string.
  S: un booleano, True si el string es un digito (y entero), False si no lo es.
  '''
  if not isinstance(input, str):
    return False
  if input == "":
    return False
  return esDigitoAux(input)


def esDigitoAux(input):
  if input == "":
    return True
  elif input[0] == "0" or input[0] == "1" or input[0] == "2" or input[
      0] == "3" or input[0] == "4" or input[0] == "5" or input[
          0] == "6" or input[0] == "7" or input[0] == "8" or input[0] == "9":
    return esDigitoAux(input[1:])
  else:
    return False
  
def Maximo(lista, indexMax=0, index=1):
  '''
  E: Una lista.
  S: El índice del número más alto de la lista.
  '''
  if index == len(lista): 
    return indexMax
  if lista[index] > lista[indexMax]:
    indexMax = index
  return Maximo(lista, indexMax, index + 1)
