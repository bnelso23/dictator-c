var v8type = null;

try{
    v8type = require('../build/Release/addon');
}catch(e){
    v8type = require('../build/Debug/addon');
}

module.exports = v8type;