/**
 * @param {number} millis
 * @return {Promise}
 */
//  The sleep function takes a positive integer millis as input.
// It then creates a Promise that resolves after millis milliseconds using the setTimeout function.
// The Promise is then awaited using the await keyword, which allows the function to pause execution until the Promise is resolved.
async function sleep(millis) {
      return new Promise(resolve => setTimeout(resolve, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */