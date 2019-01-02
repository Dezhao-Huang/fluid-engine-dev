// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <common.h>

#include <jet.gfx/texture3.h>

namespace jet {
namespace gfx {

Texture3::Texture3() {}

Texture3::~Texture3() {}

void Texture3::clear() {
    _size = Vector3UZ();

    onClear();
}

void Texture3::setTexture(const ConstArrayView3<Vector4B> &data) {
    if (data.size() == Vector3UZ()) {
        clear();
    } else if (data.size() == _size) {
        update(data);
    } else {
        clear();

        _size = data.size();

        onSetTexture(data);
    }
}

void Texture3::setTexture(const ConstArrayView3<Vector4F> &data) {
    if (data.size() == Vector3UZ()) {
        clear();
    } else if (data.size() == _size) {
        update(data);
    } else {
        clear();

        _size = data.size();

        onSetTexture(data);
    }
}

void Texture3::bind(Renderer *renderer, unsigned int slotId) {
    onBind(renderer, slotId);
}

const Vector3UZ &Texture3::size() const { return _size; }

const TextureSamplingMode &Texture3::samplingMode() const {
    return _samplingMode;
}

void Texture3::setSamplingMode(const TextureSamplingMode &mode) {
    _samplingMode = mode;
    onSamplingModeChanged(mode);
}

}  // namespace gfx
}  // namespace jet