const m = require('bindings')('morfeusz2')

function version () {
  return m.version()
}

function copyright () {
  return m.copyright()
}

function dictCopyright () {
  return m.dictCopyright()
}

function analyze (text) {
  return m.analyze(text)
}
// let text = 'asdf'
// for(let i = 0; i<100; i++) {
//   text += 'rgv'+i
//   console.log(analyze(text+'\n'))
// }
// console.log(version())
// console.log(analyze('Chciałbym kiedyś pójść gdzieś na ryby, które są mi ulubione'))

module.exports = {
  version,
  copyright,
  dictCopyright,
  analyze
}
