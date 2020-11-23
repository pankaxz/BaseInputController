
#include "CoreUObject.h"
#include "Modules/ModuleManager.h"

class  FInputTestEditorModule : public IModuleInterface
{
public:
    
    virtual void StartupModule() override;
    
    virtual void ShutdownModule() override;
};

