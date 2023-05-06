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