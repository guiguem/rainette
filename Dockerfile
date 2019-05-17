FROM gitlab-registry.in2p3.fr/t2k/applecrate:v0.0.3 as rainette_common

ARG build_type=Release
ENV RAINETTE_TAG=v0.0.1
ENV RAINETTE_BUILD_PREFIX=/usr/local/t2k/rainette/$RAINETTE_TAG
ENV RAINETTE_BUILD_TYPE=$build_type

RUN mkdir -p $RAINETTE_BUILD_PREFIX &&\
    chmod -R 777 $RAINETTE_BUILD_PREFIX/.. &&\
    cd $RAINETTE_BUILD_PREFIX &&\
    echo "source ${COMMON_BUILD_PREFIX}/setup.sh" > setup.sh &&\
    echo "export RAINETTE_TAG=${RAINETTE_TAG}" >> setup.sh &&\
    echo "export RAINETTE_BUILD_PREFIX=${RAINETTE_BUILD_PREFIX}" >> setup.sh &&\
    echo 'ln -sfT $RAINETTE_BUILD_PREFIX $RAINETTE_BUILD_PREFIX/../current' >> setup.sh &&\
    echo 'export PATH=$RAINETTE_BUILD_PREFIX/bin:$PATH' >> setup.sh &&\
    echo 'export LD_LIBRARY_PATH=$RAINETTE_BUILD_PREFIX/lib64:$RAINETTE_BUILD_PREFIX/lib:$LD_LIBRARY_PATH' >> setup.sh &&\
    echo 'export PYTHONPATH=$RAINETTE_BUILD_PREFIX/$(python -m site --user-site | sed "s%$(python -m site --user-base)%%"):$PYTHONPATH' >> setup.sh &&\
    /bin/true

# ########################
FROM rainette_common as rainette_done

COPY Applications /tmp_source/Applications
COPY cmake /tmp_source/cmake
COPY ConfigFiles /tmp_source/ConfigFiles
COPY CosmicCrisp /tmp_source/CosmicCrisp
# COPY scarab /tmp_source/scarab
COPY ToolDAQFramework /tmp_source/ToolDAQFramework
COPY UserTools /tmp_source/UserTools
COPY RainetteDataModels /tmp_source/RainetteDataModels

COPY CMakeLists.txt /tmp_source/CMakeLists.txt
COPY .git /tmp_source/.git

# repeat the cmake command to get the change of install prefix to set correctly (a package_builder known issue)
RUN source $RAINETTE_BUILD_PREFIX/setup.sh &&\
    cd /tmp_source &&\
    mkdir build &&\
    cd build &&\
    cmake -D CMAKE_BUILD_TYPE=$RAINETTE_BUILD_TYPE \
        -D CMAKE_INSTALL_PREFIX:PATH=$RAINETTE_BUILD_PREFIX \
        -D CMAKE_SKIP_INSTALL_RPATH:BOOL=True .. &&\
    cmake -D CMAKE_BUILD_TYPE=$RAINETTE_BUILD_TYPE \
        -D CMAKE_INSTALL_PREFIX:PATH=$RAINETTE_BUILD_PREFIX \
        -D CMAKE_SKIP_INSTALL_RPATH:BOOL=True .. &&\
    make -j3 install &&\
    /bin/true

# ########################
FROM rainette_common

COPY --from=rainette_done $RAINETTE_BUILD_PREFIX $RAINETTE_BUILD_PREFIX

RUN echo "export RAINETTE_TAG=${RAINETTE_TAG}" >> $RAINETTE_BUILD_PREFIX/bin/this_cosmiccrisp.sh.sh