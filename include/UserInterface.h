#include "DynamicArray.h"
#include "LinkedList.h"
#include "Ticket.h"
#include "Technician.h"

class UserInterface
{
public:
    enum class OutputMode
    {
        INTERACTIVE,
        SILENT,
    };

    struct SystemStatusInfo
    {
        int currentTime;
        const DynamicArray<Ticket *> *schedualedTickets;
        const LinkedList<Ticket *> *completedTickets;
        const LinkedList<Ticket *> *cancelledTickets;
        const DynamicArray<Technician> *technicians;
        const DynamicArray<ProblemType> *problems;
        const DynamicArray<string> *locations;
    };

private:
    OutputMode outputMode = OutputMode::INTERACTIVE;
    SystemStatusInfo sysInfo;

public:
    UserInterface();

    OutputMode askOutputMode();
    string askConfigFileName();
    void displaySystemStatus(const SystemStatusInfo &info);

private:
    void waitforEnter();

    void displaySchedualedTickets();

    void displayTechnicians();
    void displayBusyTechnicians();
    void displayFreeTechnicians();

    void displayCompletedTickets();
};