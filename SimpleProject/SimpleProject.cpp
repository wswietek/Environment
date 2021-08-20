#include "SimpleProject.hpp"

#include "Message.hpp"

namespace project
{

CommandError::CommandError()
    : std::logic_error("Error with configuration")
{}

SimpleProject::SimpleProject(Scheduler& scheduler, const std::string& command): msg_scheduler(scheduler)
{
    if (command.compare("Run HelloWorldInd") == 0)
    {
        HelloWorldInd indication;
        msg_scheduler.send(std::make_unique<Message<HelloWorldInd>>(indication));
    }
    else
    {
        throw CommandError();
    }
}

} // namespace project