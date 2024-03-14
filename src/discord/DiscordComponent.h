#ifndef DISCORDCOMPONENT_H
#define DISCORDCOMPONENT_H


#include <QObject>
#include "utils/Utils.h"
#include "ComponentManager.h"

class DiscordComponent : public ComponentBase {
    public:
        bool componentInitialize() override;
    
    
    private:
        void onStop();
        void onPause();
        void onPlaying();        
};

#endif