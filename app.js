// JAVASCIRPT
const carPath = {
    curviness: 1,
    autoRotate: true,
    values: [
        { x: 0, y: 0 },
        { x: window.innerWidth, y: 0 }
    ]
}


const tween = new TimelineLite();
tween.add(
    TweenLite.to('.car', 1, {
        bezier: carPath,
        ease: Power1.easeInOut
    })
)


const controller = new ScrollMagic.Controller();
const scene = new ScrollMagic.Scene({
    triggerElement: ".animation-section",
    duration: 5000,
    triggerHook: 0
})
.setTween(tween)
.setPin('.animation-section')
.addTo(controller);






