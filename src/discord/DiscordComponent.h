#ifndef DISCORDCOMPONENT_H
#define DISCORDCOMPONENT_H


#include <QObject>
#include <qobjectdefs.h>
#include "utils/Utils.h"
#include "ComponentManager.h"

class DiscordComponent : public ComponentBase {
    Q_OBJECT
    DEFINE_SINGLETON(DiscordComponent);

    public:
        bool componentInitialize() override;

            const char* componentName() override { return "discord"; }
            bool componentExport() override { return true; }
    
    private:
        void onStop();
        void onPause();
        void onPlaying();        
};

#endif