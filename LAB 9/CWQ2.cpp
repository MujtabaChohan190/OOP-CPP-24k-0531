#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger
{
private:
    vector<string> logs;
    const size_t maxLogs = 1000;

    void store(const string &severity, const string &module, const string &message)
    {
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }
        logs.push_back("[" + severity + "] " + module + ": " + message);
    }

public:
    void logInfo(const string &module, const string &message)
    {
        store("INFO", module, message);
    }

    void logWarning(const string &module, const string &message)
    {
        store("WARN", module, message);
    }

    void logError(const string &module, const string &message)
    {
        store("ERROR", module, message);
    }

    friend class Auditor;
};

class Auditor
{
private:
    string password;

public:
    Auditor(const string &pass)
    {
        password = pass;
    }

    vector<string> getLogs(const Logger &logger)
    {
        if (password == "admin123") {
            return logger.logs;
        }
        return {};
    }
};

int main()
{
    Logger logger;

    logger.logInfo("Network", "Connection established");
    logger.logWarning("Database", "Query took too long");
    logger.logError("Filesystem", "Disk read failed");

    Auditor auditor("admin123");
    vector<string> logs = auditor.getLogs(logger);

    for (const string &log : logs) {
        cout << log << endl;
    }

    return 0;
}
