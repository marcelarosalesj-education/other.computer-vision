# Computer Vision learning

My findings and learning on Computer Vision topics.

## Development environment
I'm using the Docker container from [Learn OpenCV](https://www.learnopencv.com/install-opencv-docker-image-ubuntu-macos-windows/) website.
After installing docker and the pulling the container use this command:
```
docker pull spmallick/opencv-docker:opencv
docker run -v $(pwd):/localdisk --device=/dev/video0:/dev/video0 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 -it spmallick/opencv-docker:opencv /bin/bash

docker start  <container_hash>
docker attach <container_hash>
```

## Object detection
Based on the content of [Deteccion de objetos](https://www.coursera.org/learn/deteccion-objetos) course in Coursera.
