all: main

main: Resource.o Container.o Pod.o Server.o KubernetesCluster.o Cloud_Util.o main.o
	@echo "Linking object files to create the executable..."
	g++ -g -Wall -Wextra --std=c++23 Resource.o Container.o Pod.o Server.o KubernetesCluster.o Cloud_Util.o main.o -o main

Resource.o: Resource.cpp Resource.hpp
	@echo "Compiling Resource.cpp"
	g++ -c -Wall -Wextra --std=c++23 Resource.cpp

Container.o: Container.cpp Container.hpp Resource.hpp
	@echo "Compiling Container.cpp"
	g++ -c -Wall -Wextra --std=c++23 Container.cpp

Pod.o: Pod.cpp Pod.hpp Container.hpp Resource.hpp
	@echo "Compiling Pod.cpp"
	g++ -c -Wall -Wextra --std=c++23 Pod.cpp

Server.o: Server.cpp Server.hpp Resource.hpp
	@echo "Compiling Server.cpp"
	g++ -c -Wall -Wextra --std=c++23 Server.cpp

KubernetesCluster.o: KubernetesCluster.cpp KubernetesCluster.hpp Pod.hpp Server.hpp
	@echo "Compiling KubernetesCluster.cpp"
	g++ -c -Wall -Wextra --std=c++23 KubernetesCluster.cpp

Cloud_Util.o: Cloud_Util.cpp Cloud_Util.hpp KubernetesCluster.hpp
	@echo "Compiling Cloud_Util.cpp"
	g++ -c -Wall -Wextra --std=c++23 Cloud_Util.cpp

main.o: main.cpp Cloud_Util.hpp KubernetesCluster.hpp Pod.hpp Server.hpp Container.hpp Resource.hpp
	@echo "Compiling main.cpp"
	g++ -c -Wall -Wextra --std=c++23 main.cpp

clean:
	rm -f *.o main
	@echo "Cleaned up object files and executable."
