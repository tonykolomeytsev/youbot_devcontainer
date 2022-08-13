FROM ubuntu:20.04 as builder
# install required packages
RUN apt update && \
    DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC \
    apt install -y --no-install-recommends \
    git \
    cmake \
    libboost-all-dev \
    build-essential

# build and install youbot driver
RUN git config --global http.sslverify false && \
    git clone --depth 1 https://github.com/tonykolomeytsev/youbot_driver.git && \
    mkdir youbot_driver/build && \
    cd youbot_driver/build && \ 
    cmake .. && \
    make -j$(nproc) && \
    make install

FROM ubuntu:20.04 as main
# install required packages
RUN apt update && \
    DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC \
    apt install -y --no-install-recommends \
    git \
    cmake \
    libboost-all-dev \
    build-essential && \
    # free disk space
    apt autoclean && \
    # colored prompt
    sed -i 's/#force_color_prompt=yes/force_color_prompt=yes/g' ~/.bashrc

# copy prebuilt youbot driver to clear system
COPY --from=builder /usr/local/include /usr/local/include
COPY --from=builder /usr/local/config /usr/local/config
COPY --from=builder /usr/local/lib /usr/local/lib
COPY --from=builder /usr/local/bin /usr/local/bin

# provide util for youbot projects creation
COPY youbot_new_project /usr/local/bin/youbot_new_project
COPY .template /root/.template

WORKDIR /root/workspace
