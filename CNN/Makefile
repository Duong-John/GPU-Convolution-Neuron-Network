CXX = g++
NVCC = nvcc

CUDA_PATH ?= C:/Program\ Files/NVIDIA\ GPU\ Computing\ Toolkit/CUDA/v12.9

CXXFLAGS = -ISDL/include -Iinclude -Itensor -I"$(CUDA_PATH)/include" -std=c++20
LDFLAGS  = -L"$(CUDA_PATH)/lib/x64" -lcuda -lcudart -LSDL/lib1 -LSDL/lib2 -lSDL2 -lSDL2_image

SRCS = src/Layer.cpp src/Loss.cpp src/Driver_Singleton.cpp src/ReLU.cpp src/Softmax.cpp src/Convolution_CUDA.cpp src/Max_Pooling.cpp src/Dataset.cpp Util.cpp main.cpp
OBJS = $(SRCS:%.cpp=build/%.o)

PTX_FILE = CUDA_code/conv_kernel.ptx
CU_SRC   = CUDA_code/conv_kernel.cu

# Default:
all: program

# Build CUDA PTX:
$(PTX_FILE): $(CU_SRC)
	mkdir -p $(dir $@)
	$(NVCC) -arch=sm_89 -ptx $< -o $@

# Build individual .cpp -> .o
build/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Link all:
program: $(OBJS) $(PTX_FILE)
	$(CXX) $(OBJS) -o program $(LDFLAGS)

# Build one file: make buildone FILE=src/Layer.cpp
buildone:
	@if [ -z "$(FILE)" ]; then \
		echo "ERROR: Wrong Syntax"; \
		exit 1; \
	fi
	mkdir -p build/$(dir $(FILE))
	$(CXX) -c $(FILE) -o build/$(basename $(FILE)).o $(CXXFLAGS)

# Clean all
clean:
	rm -rf build program $(PTX_FILE)