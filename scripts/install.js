const os = require('os')
const https = require('https')
const fs = require('fs')
const util = require('util')
const exec = util.promisify(require('child_process').exec)

const filesMap = require('./filesMap.json')

const supportedPlatforms = ['darwin_x64', 'linux_x64']
const platform = os.platform()
const arch = os.arch()

function downloadFile (url, from, target) {
  return new Promise((resolve, reject) => {
    https.get(url, response => {
      if (response.statusCode !== 200) return reject(`Coulnt't download file: ${from}`)

      const writeStream = fs.createWriteStream(target)
      response.pipe(writeStream)

      writeStream.on('error', () => reject(`Couldn't write file to: ${target}`))
      writeStream.on('finish', () => writeStream.close(resolve))
    })
  })
}

async function install () {
  try {
    if (supportedPlatforms.indexOf(`${platform}_${arch}`) === -1) {
      console.log('\nYour platform is not supported. Supported platforms:')
      for (const p of supportedPlatforms) console.log(`  * ${p}`)
      console.log('')
      process.exit(1)
    }

    const subversion = '20191006'
    const baseUrl = `https://raw.githubusercontent.com/maxtomczyk/morfeusz2-files/master/files/${platform}/${arch}/${subversion}`
    console.log(`Identified platform as ${platform}_${arch}`)
    console.log(`\nLibrary file for Morfeusz 2 subversion ${subversion} will be downloaded.`)
    const files = filesMap[platform]
    for (const file of files) {
      if (fs.existsSync(file.to)) {
        console.log(`${file.to} already exists, skipping...`)
        continue
      }
      console.log(`Downloading ${file.from} -> ${file.to}`)
      await downloadFile(baseUrl + file.from, file.from, file.to)
    }
    console.log('')

    if (platform === 'linux') {
      const ldPath = process.env.LD_LIBRARY_PATH
      const dirRegexp = new RegExp(process.cwd(), 'gmi')
      if (dirRegexp.test(ldPath)) {
        console.log('Detected node-morfeusz2 in LD_LIBRARY_PATH')
        process.exit(0)
      }
      console.log('Package directory is not in LD_LIBRARY_PATH, adding to .bashrc...')
      const home = os.homedir()
      fs.appendFileSync(`${home}/.bashrc`, `\nexport LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${process.cwd()}\n`)
      const { stderr } = await exec('.', [`${home}/.bashrc`])
      if (stderr.toString()) {
        console.log('Unable to export LD_LIBRARY_PATH in .bashrc, you will need to specify this env manually when starting project.')
      }
      process.exit(0)
    }
  } catch (e) {
    console.log(e)
    process.exit(1)
  }
}

install()
