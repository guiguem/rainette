# Rainette

## Installation instructions

- mkdir build
- cd build
- cmake ..
- make -j3
- make install

## Using Docker

### Pull a Docker image

Images representing the master branch installation are available on the IN2P3 Gitlab and you can pull them from there.
This method is recommanded when you just want to run the software and you don't need to edit the source code.
First login to Gitlab:

```bash
docker login gitlab-registry.in2p3.fr
```

Then pull the version you wish to use, e.g.:

```bash
docker pull gitlab-registry.in2p3.fr/t2k/rainette:develop
```

(note the change of the version tag at the end of the command).

Finally, run the image:

```bash
docker run --rm -it gitlab-registry.in2p3.fr/t2k/rainette:develop
```

You can also mount a folder inside the container (to access host computer data for example):

```bash
docker run -v <local-folder>:/host--rm -it gitlab-registry.in2p3.fr/t2k/rainette:develop
```

Final step: source the environment in the container:

```bash
source /usr/local/t2k/rainette/v0.0.1/setup.sh
```

### Create the image locally

You can build a Docker image by using your local cloned repository of Rainette.
Inside the Rainette folder, run:

```bash
docker build -i rainette .
```

This will install the software inside the container and produce a `rainette` image.
You can then access the software by running:
```bash
docker run --rm -it rainette
source /usr/local/t2k/rainette/v0.0.1/setup.sh
```

You can then edit the code contained in the container and reinstall it by going into `\tmp_source/build` and running:

```bash
make -j3 install
```
