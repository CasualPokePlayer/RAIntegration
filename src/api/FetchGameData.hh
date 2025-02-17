#ifndef RA_API_FETCH_GAME_DATA_HH
#define RA_API_FETCH_GAME_DATA_HH
#pragma once

#include "ApiCall.hh"

namespace ra {
namespace api {

class FetchGameData
{
public:
    static constexpr const char* const Name() noexcept { return "FetchGameData"; }

    struct Response : ApiResponseBase
    {
        std::wstring Title;
        unsigned int ConsoleId{};
        std::string ImageIcon;
        std::string RichPresence;

        struct Achievement
        {
            unsigned int Id{};
            std::string Title;
            std::string Description;
            unsigned int CategoryId{};
            unsigned int Points{};
            std::string Definition;
            std::string Author;
            std::string BadgeName;
            time_t Created{};
            time_t Updated{};
        };
        std::vector<Achievement> Achievements;

        struct Leaderboard
        {
            unsigned int Id{};
            std::string Title;
            std::string Description;
            std::string Definition;
            int Format{ 0 };
            bool LowerIsBetter{ false };
            bool Hidden{ false };
        };
        std::vector<Leaderboard> Leaderboards;
    };

    struct Request : ApiRequestBase
    {
        unsigned int GameId{ 0U };

        using Callback = std::function<void(const Response& response)>;

        Response Call() const;

        void CallAsync(Callback&& callback) const
        {
            ApiRequestBase::CallAsync<Request, Callback>(*this, std::move(callback));
        }
    };
};

} // namespace api
} // namespace ra

#endif // !RA_API_FETCH_GAME_DATA_HH
