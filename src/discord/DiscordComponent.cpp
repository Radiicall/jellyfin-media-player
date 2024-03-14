#include <QTimer>
#include "DiscordComponent.h"
#include "iostream"
#include "PlayerComponent.h"
#include "system/SystemComponent.h"
#include "settings/SettingsComponent.h"
#include "settings/SettingsSection.h"

bool DiscordComponent::componentInitialize(){
    std::cout << "rpc init" << std::endl;
    return true;
}
