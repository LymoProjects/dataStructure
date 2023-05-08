#pragma once

#include <iterator>

auto fqs(auto begin, auto end, auto && comp) -> void {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto leftSaver {std::next(begin)};
    auto rightSaver {std::prev(end)};

    auto mover {leftSaver};

    while (mover != std::next(rightSaver)) {
        if (comp(*mover, *begin)) {
            std::swap(*mover, *leftSaver);

            ++leftSaver;
            ++mover;
        } else if (comp(*begin, *mover)) {
            std::swap(*mover, *rightSaver);

            --rightSaver;
        } else {
            ++mover;
        }
    }

    std::swap(*begin, *std::prev(leftSaver));

    fqs(begin, leftSaver, comp);
    fqs(std::next(rightSaver), end, comp);
}

namespace exp__ {
    auto quickSort(auto begin, auto end, auto && comp) -> void {
        if (std::distance(begin, end) < 2) {
            return;
        }

        auto savers {std::make_pair(std::next(begin), std::prev(end))};

        auto mover {std::next(begin)};

        while (mover != std::next(savers.second)) {
            if (comp(*mover, *begin)) {
                std::swap(*savers.first, *mover);

                ++savers.first;

                ++mover;
            } else if (comp(*begin, *mover)) {
                std::swap(*savers.second, *mover);

                --savers.second;
            } else {
                ++mover;
            }
        }

        std::swap(*begin, *std::prev(savers.first));

        quickSort(begin, savers.first, comp);
        quickSort(std::next(savers.second), end, comp);
    }
}