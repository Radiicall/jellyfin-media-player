#ifndef DISCORDCOMPONENT_H
#define DISCORDCOMPONENT_H


#include <QObject>
#include <qobjectdefs.h>
#include "utils/Utils.h"
#include "ComponentManager.h"


extern "C" {
uintptr_t rpc_add(uintptr_t left, uintptr_t right);
void print_hello();
}


class DiscordComponent : public ComponentBase {
    Q_OBJECT
    DEFINE_SINGLETON(DiscordComponent);

    public:
        bool componentInitialize() override;
        void componentPostInitialize() override;

        const char* componentName() override { return "discord-rpc"; }
        bool componentExport() override { return true; }
        explicit DiscordComponent(QObject* parent = nullptr): ComponentBase(parent) {}

    private:

    private slots:
        void RunCallbacks();

};

#endif