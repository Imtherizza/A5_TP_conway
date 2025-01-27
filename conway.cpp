#include "conway.h"
#include <optional>
#include <torch/extension.h>

class GameOfLife {
public:
  void step(torch::Tensor grid_in, torch::Tensor grid_out,
            std::optional<torch::Stream> stream = std::nullopt) {
    game_of_life_step(grid_in, grid_out, stream);
  }
};

PYBIND11_MODULE(conway, m) {
  py::class_<GameOfLife>(m, "GameOfLife")
      .def(py::init<>())
      .def("step", &GameOfLife::step);
}
