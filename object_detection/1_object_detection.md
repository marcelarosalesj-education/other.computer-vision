# Object Detection course notes - Week 1

## Object Detection system overview
* Feature/descriptor extraction to generate candidates
* Classification of candidates
* Decision methods
* Performance evaluation

## Detection system architecture
* Input: image
* Object Detection system
* Output: window of objects detected

## The image
* made of pixels
* 3 channels RGB (0-255)
* intensity

### How a pixel is defined?
* Light color
* Object material
* Camera sensitivity sensors

### Images representation
* RGB
* NIR-RGB (Near Infrarred)
* Long-wavelenght Infrarred
* RGBD (depth)

# Descriptores

## Basados en caracteristicas del pixel
### Imagen con cambios de luz
* Una solucion es pasar a coordenadas cromaticas, eliminando la intensidad, usando 2 canales

### Imagen con luces de diferentes colores
* Hay que intentar eliminar los efectos del cambio de luz y pasar a una imagen canonica. Ej algoritmo white-patch.

## basados en toda la imagen
## basados en caracteristicas locales
* convolucion
* kernel

# Algoritmos basicos de deteccion de objetos

## Etiquetado de regiones conexas (labelling)
* connectividad a 4 (4-connectivity)
* connectividad a 8 (8-connectivity)  

Algoritmo:
* primer recorrido: etiqueta y anota equivalencias
* resuelve equivalencias y re-etiqueta
## Template matching
* la ventana que mas se parezca al objeto que queremos detectar
* el template describe el objeto que queremos detectar  

Algoritmo:  
* cada punto se le asigna un valor que representa la semejanza entre el patron y la ventana
    * Disimilitud
    * Similitud
* se localiza la ventana o ventanas extrayendo los minimos locales del mapa de diferencias anterior