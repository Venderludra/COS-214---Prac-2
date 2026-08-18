CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = wayfarer

SOURCES = \
	main.cpp \
	TravelMode.cpp \
	RouteStrategy.cpp \
	Place.cpp \
	Region.cpp \
	PlaceDecorator.cpp \
	Quest.cpp \
	Toll.cpp \
	World.cpp \
	BiomeFactory.cpp \
	DesertFactory.cpp \
	DesertTerrain.cpp \
	DesertNPC.cpp \
	DesertObstacle.cpp \
	AquaticFactory.cpp \
	AquaticTerrain.cpp \
	AquaticNPC.cpp \
	AquaticObstacle.cpp \
	ForestFactory.cpp \
	ForestTerrain.cpp \
	ForestNPC.cpp \
	ForestObstacle.cpp \
	InfernoFactory.cpp \
	InfernoTerrain.cpp \
	InfernoNPC.cpp \
	InfernoObstacle.cpp \
	SpaceFactory.cpp \
	SpaceTerrain.cpp \
	SpaceNPC.cpp \
	SpaceObstacle.cpp \
	Terrain.cpp \
	NPC.cpp \
	Obstacle.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean