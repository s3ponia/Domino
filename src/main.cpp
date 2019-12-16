#define NDEBUG
#include "headers/Game.h"
#include "headers/RealPlayer.h"
#include <tuple>

int main() {
    Boneyard boneyard({});
    RealPlayer realPlayer(boneyard);
    boneyard.GetDominoBlock(&realPlayer);
}