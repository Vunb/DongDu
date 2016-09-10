var dongdu = require('bindings')('dongdu');

var predictor = dongdu.getPredictor();

console.log(predictor.segment("Chào mừng bạn đến với đất nước Việt Nam!!"));
console.log(predictor.segment("Hôm nay là một ngày rất đẹp trời. Bình minh xua đi bóng tối"));
console.log(predictor.segmentF("conversations.txt"));
