/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** IndieModel
*/

#ifndef INDIEMODEL_HPP_
#define INDIEMODEL_HPP_

#include <memory>
#include <irrlicht.h>
#include <unordered_map>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace irl
{
    class Object3dImpl {
        public:
            class Animation
            {
                public:
                    Animation() = default;
                    Animation(int start);
                    Animation(int start, int end, bool loop = true, f32 speed = 0);
                    ~Animation() = default;

                    [[nodiscard]] int getStart(void) const;
                    [[nodiscard]] int getEnd(void) const;
                    [[nodiscard]] bool isLooped(void) const;
                    [[nodiscard]] f32 getSpeed(void) const;
                private:
                    int _start;
                    int _end;
                    f32 _speed;
                    bool _loop;
                public:
                    class Object3dAnimationCallback : public scene::IAnimationEndCallBack
                    {
                        public:
                            void OnAnimationEnd(IAnimatedMeshSceneNode* node) override;
                    };
            };
        public:
            Object3dImpl();
            virtual ~Object3dImpl();

            void setMesh(const std::string &path);
            void renderModel(vector3df &pos, vector3df &rotation);
            void setMaterialTexture(u32 material, ITexture *texture);
            void setMaterialType(u32 material, E_MATERIAL_TYPE type);
            void setPos(const vector3df &pos);
            void setPos(float x, float y, float z);
            void setRotation(vector3df &pos);
            void setRotation(float x, float y, float z);
            [[nodiscard]] vector3df getPos(void) const;
            [[nodiscard]] float getX(void) const;
            [[nodiscard]] float getY(void) const;
            [[nodiscard]] float getZ(void) const;
            IAnimatedMeshSceneNode *get3dObject(void) const;
            void playAnimation(const std::string &name);
            void addAnimation(const std::string &name, Animation &anim);
            void clear(void);
        protected:
            IAnimatedMesh *_mesh;
            IAnimatedMeshSceneNode *_3dObject;
            std::unordered_map<std::string, Animation> _anims;
            std::string _name;
            f32 _defaultSpeed;
    };

    class Object3d : public Object3dImpl {
        public:
            Object3d &operator=(Object3d &model);
    };
}

#endif /* !INDIEMODEL_HPP_ */